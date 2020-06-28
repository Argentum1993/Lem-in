/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 19:10:35 by astamm            #+#    #+#             */
/*   Updated: 2019/12/16 15:49:44 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_list_edges(t_current_list_edges *list_edges)
{
	t_list_edges_current_room *copy;

	while (list_edges->head != 0)
	{
		copy = list_edges->head;
		list_edges->head = list_edges->head->next;
		ft_memdel((void**)&copy);
	}
}

void	free_map_rooms(t_valid_pars *vp)
{
	t_list_map	*copy;

	vp->map_rooms->list = vp->map_rooms->head;
	while (vp->map_rooms->list != 0)
	{
		copy = vp->map_rooms->list;
		vp->map_rooms->list = vp->map_rooms->list->next;
		ft_memdel((void**)&copy->str);
		ft_memdel((void**)&copy);
	}
	ft_memdel((void**)&vp->map_rooms);
}

void	free_map_edges(t_valid_pars *vp)
{
	t_list_map	*copy;

	vp->map_edges->list = vp->map_edges->head;
	while (vp->map_edges->list != 0)
	{
		copy = vp->map_edges->list;
		vp->map_edges->list = vp->map_edges->list->next;
		ft_memdel((void**)&copy->str);
		ft_memdel((void**)&copy);
	}
	ft_memdel((void**)&vp->map_edges);
}
