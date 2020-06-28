/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_no_intersections_ways.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 04:43:08 by astamm            #+#    #+#             */
/*   Updated: 2019/12/17 14:57:27 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	mark_not_visited_without_lock(t_room *m_room)
{
	if (!m_room->lock)
		m_room->visited = False;
	if (m_room->in && !m_room->in->lock)
		m_room->in->visited = False;
	if (m_room->out && !m_room->out->lock)
		m_room->out->visited = False;
}

static void	mark_unlock(t_room *m_room)
{
	int			index_edge;

	index_edge = 0;
	while (index_edge < m_room->amount_edge)
	{
		m_room->arr_edge[index_edge]->next_room->lock = False;
		if (m_room->arr_edge[index_edge]->next_room->in)
			m_room->arr_edge[index_edge]->next_room->in->lock = False;
		if (m_room->arr_edge[index_edge]->next_room->out)
			m_room->arr_edge[index_edge]->next_room->out->lock = False;
		mark_rooms_not_visited(m_room->arr_edge[index_edge]->next_room);
		index_edge++;
	}
}

static void	lock_all_room_in_way(t_way *way)
{
	int		index_room;
	int		last_index;
	t_room	**rooms;

	index_room = 1;
	rooms = way->arr_rooms;
	last_index = way->amount_room - 2;
	while (index_room <= last_index)
	{
		rooms[index_room++]->lock = True;
	}
}

t_arry_way	get_no_intersections_ways(t_graf *clean_graf)
{
	t_way		short_way;
	t_arry_way	no_ntrs_ways;
	int			index_way;

	ft_bzero(&no_ntrs_ways, sizeof(t_arry_way));
	index_way = 0;
	while (index_way < MAX_NTRS_WAYS)
	{
		short_way = bfs_algorithm(clean_graf);
		if (short_way.amount_room > 0)
			lock_all_room_in_way(&short_way);
		map_for_each_rooms(clean_graf, mark_not_visited_without_lock);
		if (short_way.amount_room <= 0)
		{
			no_ntrs_ways.amount = index_way;
			map_for_each_rooms(clean_graf, mark_unlock);
			mark_unlock(no_ntrs_ways.ways[0].arr_rooms[0]);
			return (no_ntrs_ways);
		}
		no_ntrs_ways.ways[index_way++] = short_way;
	}
	map_for_each_rooms(clean_graf, mark_unlock);
	return (no_ntrs_ways);
}
