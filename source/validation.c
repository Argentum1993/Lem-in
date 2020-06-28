/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <wmaykit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 15:55:04 by astamm            #+#    #+#             */
/*   Updated: 2019/12/17 16:26:48 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	valid_begin(t_valid_pars *vp, int *i)
{
	t_list_map *new;

	if (*i == 1)
	{
		valid_amounts_ants(&vp->str);
		vp->map_rooms = (t_map*)malloc(sizeof(t_map));
		ft_bzero((void*)vp->map_rooms, sizeof(t_map));
		new = (t_list_map*)malloc(sizeof(t_list_map));
		ft_bzero((void*)new, sizeof(t_list_map));
		new->str = vp->str;
		vp->map_rooms->head = new;
		vp->map_rooms->list = vp->map_rooms->head;
		*i = 0;
		vp->map_edges = (t_map*)malloc(sizeof(t_map));
		ft_bzero((void*)vp->map_edges, sizeof(t_map));
	}
	else if (vp->str[0] == '#' && vp->str[1] != '#')
		valid_save_comment(vp);
	else if (vp->links_processing == False && !ft_strchr(vp->str, '-'))
		valid_str_room(vp);
	else if (vp->str[0] != '#')
		valid_str_link(vp);
	else
		print_error_and_free_mem(vp, "Invalid line");
}

int			validation(t_lem_in *lm)
{
	t_valid_pars	vp;
	int				i;
	int				size;

	ft_bzero((void*)&vp, sizeof(t_valid_pars));
	i = 1;
	while ((size = get_next_line(0, &vp.str)) > 0)
		valid_begin(&vp, &i);
	if (size == -1)
		error_processing("Invalid file");
	if (vp.start == 0 || vp.end == 0)
		error_processing("No start or end");
	parsing(lm, &vp);
	free_map_rooms(&vp);
	free_map_edges(&vp);
	return (1);
}
