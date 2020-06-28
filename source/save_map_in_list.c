/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map_in_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 00:26:13 by astamm            #+#    #+#             */
/*   Updated: 2019/12/16 00:27:51 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	valid_save_map_rooms(t_valid_pars *vp)
{
	t_list_map *new;

	new = (t_list_map*)malloc(sizeof(t_list_map));
	ft_bzero((void*)new, sizeof(t_list_map));
	new->str = vp->str;
	vp->map_rooms->list->next = new;
	vp->map_rooms->list = vp->map_rooms->list->next;
	vp->amount_rooms++;
}

void	valid_save_map_edges(t_valid_pars *vp)
{
	t_list_map *new;

	new = (t_list_map*)malloc(sizeof(t_list_map));
	ft_bzero((void*)new, sizeof(t_list_map));
	new->str = vp->str;
	vp->map_edges->list->next = new;
	vp->map_edges->list = vp->map_edges->list->next;
}

void	valid_inicial_map_edges(t_valid_pars *vp)
{
	t_list_map *new;

	new = (t_list_map*)malloc(sizeof(t_list_map));
	ft_bzero((void*)new, sizeof(t_list_map));
	new->str = vp->str;
	vp->map_edges->head = new;
	vp->map_edges->list = vp->map_edges->head;
}

void	valid_save_comment(t_valid_pars *vp)
{
	if (vp->map_edges->head == NULL)
	{
		valid_save_map_rooms(vp);
		vp->amount_rooms--;
	}
	else
		valid_save_map_edges(vp);
}
