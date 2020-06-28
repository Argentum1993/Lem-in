/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print_content_graf.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <wmaykit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:07:47 by wmaykit           #+#    #+#             */
/*   Updated: 2019/12/15 14:21:22 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	print_edge_in_room(t_room *i_room, int i_indent)
{
	int		index;
	t_edge	**edges;

	if (!i_room)
		return ;
	index = 0;
	edges = i_room->arr_edge;
	while (index < i_room->amount_edge)
	{
		ft_printf("%*sedge: from %-6s ", i_indent, "", i_room->name);
		if (edges[index]->next_room)
			ft_printf("to %-6s\n", edges[index]->next_room->name);
		else
			ft_printf("to %-6s\n", "NULL");
		++index;
	}
}

static void	print_name_room(t_room *room, int i_indent)
{
	if (room)
	{
		ft_printf("%*sroom: name[%s] ", i_indent, "", room->name);
		ft_printf("index[%d]\n", room->index);
	}
}

void		print_content_graf(t_graf *i_graf)
{
	int		index_room;
	t_room	*current_room;

	index_room = 0;
	while (index_room < i_graf->amount_rooms)
	{
		current_room = i_graf->rooms[index_room];
		print_name_room(current_room, 0);
		print_edge_in_room(current_room, 3);
		print_name_room(current_room->in, 6);
		print_edge_in_room(current_room->in, 9);
		print_name_room(current_room->out, 6);
		print_edge_in_room(current_room->out, 9);
		ft_printf("\n");
		++index_room;
	}
}
