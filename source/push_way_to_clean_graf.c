/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_way_to_clean_graf.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 17:47:43 by wmaykit           #+#    #+#             */
/*   Updated: 2019/12/17 01:16:19 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	push_way_to_clean_graf(t_graf *m_graf, t_way *i_insert_way)
{
	t_room	**rooms;
	int		amount_room;
	int		next_room;
	int		current_room;
	int		index_edge;

	current_room = 0;
	next_room = current_room + 1;
	rooms = i_insert_way->arr_rooms;
	amount_room = i_insert_way->amount_room;
	while (next_room < amount_room)
	{
		index_edge = get_index_edge(m_graf->rooms[rooms[next_room]->index],
													rooms[current_room]->index);
		if (index_edge == NO_EDGE)
		{
			add_edge_by_index(m_graf, rooms[current_room]->index,
													rooms[next_room]->index);
		}
		else
			del_edge_in_room(m_graf->rooms[rooms[next_room]->index],
																	index_edge);
		++next_room;
		++current_room;
	}
}
