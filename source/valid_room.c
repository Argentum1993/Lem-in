/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <wmaykit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 01:04:55 by astamm            #+#    #+#             */
/*   Updated: 2019/12/17 18:40:00 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		valid_name_room(char *str, int *i)
{
	if ((ft_isalpha(str[*i]) == 0) && (ft_isdigit(str[*i]) == 0))
		if (str[*i] != '_')
			error_processing("Invalid name room");
	while (str[*i] != ' ' && str[*i] != '-' && str[*i] != '\0')
	{
		if ((ft_isalpha(str[*i]) == 0) && (ft_isdigit(str[*i]) == 0))
			if (str[*i] != '_')
				error_processing("Invalid name room");
		++(*i);
	}
}

static void	valid_room(t_valid_pars *vp)
{
	vp->i = 0;
	valid_name_room(vp->str, &vp->i);
	if (vp->str[vp->i] == ' ' && vp->str[vp->i + 1] != ' ')
	{
		valid_coord_room(vp);
		valid_save_map_rooms(vp);
	}
	else
		print_error_and_free_mem(vp, "Invalid name room");
}

void		valid_str_room(t_valid_pars *vp)
{
	if (ft_strcmp(vp->str, "##start") == 0)
	{
		if (vp->start > 0)
			error_processing("Double start or end");
		vp->start = 1;
		valid_save_map_rooms(vp);
		vp->amount_rooms--;
	}
	else if (ft_strcmp(vp->str, "##end") == 0)
	{
		if (vp->end > 0)
			error_processing("Double start or end");
		vp->end = 1;
		valid_save_map_rooms(vp);
		vp->amount_rooms--;
	}
	else if (vp->str[0] == 'L')
		error_processing("Invalid name room L");
	else if (vp->str[0] != 'L')
		valid_room(vp);
	else
		print_error_and_free_mem(vp, "Invalid line in room list");
}
