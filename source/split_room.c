/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 13:15:25 by wmaykit           #+#    #+#             */
/*   Updated: 2019/12/17 01:17:27 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	chenge_link_edge_in_last_room(t_room *last_room,
															t_room *penult_room)
{
	int		index_penult_room;

	index_penult_room = get_index_edge(last_room, penult_room->index);
	last_room->arr_edge[index_penult_room]->next_room = penult_room->out;
}

void		split_rooms_in_way(t_way *m_way)
{
	int		index_room;
	int		index_penult;
	t_room	**way_rooms;

	index_room = 1;
	way_rooms = m_way->arr_rooms;
	index_penult = m_way->amount_room - 2;
	while (index_room <= index_penult)
	{
		if (!way_rooms[index_room]->parent && !way_rooms[index_room]->in &&
				!way_rooms[index_room]->out)
		{
			put_room_in(way_rooms[index_room]);
			put_room_out(way_rooms[index_room]);
		}
		++index_room;
	}
	if (m_way->amount_room >= 2)
		chenge_link_edge_in_last_room(way_rooms[m_way->amount_room - 1],
											way_rooms[m_way->amount_room - 2]);
}
