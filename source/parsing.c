/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <wmaykit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 17:03:36 by wmaykit           #+#    #+#             */
/*   Updated: 2019/12/17 15:46:33 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	valid_after_parsing(t_lem_in *lm, t_valid_pars *vp)
{
	if (lm->graf.start == NULL || lm->graf.end == NULL)
	{
		free_map_rooms(vp);
		free_map_edges(vp);
		destroy_graf(&lm->graf);
		error_processing("No start or end");
	}
	else if (lm->graf.start->amount_edge == 0 || lm->graf.end->amount_edge == 0)
	{
		free_map_rooms(vp);
		free_map_edges(vp);
		destroy_graf(&lm->graf);
		error_processing("No link at start or end");
	}
}

static void	parsing_record_edges_room(t_room *room, t_current_list_edges
																	*list_edges)
{
	int index_edge;

	index_edge = 0;
	list_edges->list = list_edges->head;
	room->arr_edge = (t_edge**)malloc(sizeof(t_edge*) *
													list_edges->amount_edges);
	ft_bzero(room->arr_edge, sizeof(t_edge*) * list_edges->amount_edges);
	while (list_edges->list != 0 && index_edge < list_edges->amount_edges)
	{
		room->arr_edge[index_edge] = (t_edge*)malloc(sizeof(t_edge));
		ft_bzero((void*)room->arr_edge[index_edge], sizeof(t_edge));
		room->arr_edge[index_edge]->next_room = list_edges->list->room;
		index_edge++;
		list_edges->list = list_edges->list->next;
	}
	room->amount_edge = list_edges->amount_edges;
	free_list_edges(list_edges);
}

static void	init_parsing(t_lem_in *lm, t_valid_pars *vp)
{
	vp->start = 0;
	vp->end = 0;
	vp->map_rooms->list = vp->map_rooms->head;
	lm->colony.amount_ants = ft_atoi(vp->map_rooms->list->str);
	vp->map_rooms->list = vp->map_rooms->list->next;
	lm->graf.rooms = (t_room**)malloc(sizeof(t_room*) * vp->amount_rooms);
	ft_bzero((void*)lm->graf.rooms, sizeof(t_room*) * vp->amount_rooms);
	lm->graf.amount_rooms = vp->amount_rooms;
	vp->list_edges =
					(t_current_list_edges*)malloc(sizeof(t_current_list_edges));
	ft_bzero(vp->list_edges, sizeof(t_current_list_edges));
}

int			parsing(t_lem_in *lm, t_valid_pars *vp)
{
	init_parsing(lm, vp);
	vp->index_current_room = -1;
	while (vp->map_rooms->list != 0)
	{
		parsing_begin_room(lm, vp);
		vp->map_rooms->list = vp->map_rooms->list->next;
	}
	parsing_check_valid_links(lm, vp);
	vp->index_current_room = 0;
	while (vp->index_current_room < vp->amount_rooms)
	{
		vp->map_edges->list = vp->map_edges->head;
		parsing_links(lm, vp);
		parsing_record_edges_room(lm->graf.rooms[vp->index_current_room],
																vp->list_edges);
		vp->index_current_room++;
	}
	ft_memdel((void**)&vp->list_edges);
	valid_after_parsing(lm, vp);
	print_map(vp);
	return (1);
}

void		print_map(t_valid_pars *vp)
{
	vp->map_rooms->list = vp->map_rooms->head;
	vp->map_edges->list = vp->map_edges->head;
	while (vp->map_rooms->list != 0)
	{
		ft_printf("%s\n", vp->map_rooms->list->str);
		vp->map_rooms->list = vp->map_rooms->list->next;
	}
	while (vp->map_edges->list != 0)
	{
		ft_printf("%s\n", vp->map_edges->list->str);
		vp->map_edges->list = vp->map_edges->list->next;
	}
	ft_printf("\n");
}
