/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_coord_room.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 01:06:51 by astamm            #+#    #+#             */
/*   Updated: 2019/12/17 15:21:43 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		valid_amounts_ants(char **str)
{
	char *number;

	if (!ft_isdigit((int)*str[0]) || *str[0] == '-')
	{
		ft_memdel((void**)str);
		error_processing("Invalid amounts ants");
	}
	number = ft_itoa(ft_atoi(*str));
	if (ft_strcmp(*str, number) != 0)
	{
		ft_memdel((void**)str);
		ft_strdel(&number);
		error_processing("Invalid amounts ants");
	}
	ft_strdel(&number);
}

static void	valid_check_coord_room(char *str, int len_int, int event)
{
	char *number;

	number = ft_itoa(ft_atoi(str));
	if (event == 1)
	{
		if (ft_strncmp(str, number, len_int) != 0)
		{
			ft_strdel(&number);
			error_processing("Invalid room coordinates");
		}
	}
	else if (ft_strcmp(str, number) != 0)
	{
		ft_strdel(&number);
		error_processing("Invalid room coordinates");
	}
	ft_strdel(&number);
}

void		valid_coord_room(t_valid_pars *vp)
{
	int	k;

	k = ++vp->i;
	while (ft_isdigit(vp->str[k]) == 1)
		k++;
	valid_check_coord_room(vp->str + vp->i, k - vp->i, 1);
	vp->i = k;
	if (vp->str[vp->i] == ' ' && vp->str[vp->i + 1] != ' ')
		vp->i++;
	else
		print_error_and_free_mem(vp, "Invalid room coordinates");
	valid_check_coord_room(vp->str + vp->i, 0, 2);
	while (ft_isdigit(vp->str[vp->i]) == 1)
		vp->i++;
	if (vp->str[vp->i] != '\0')
		print_error_and_free_mem(vp, "Invalid room coordinates");
}
