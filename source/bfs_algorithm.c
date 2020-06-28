/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 22:27:04 by wmaykit           #+#    #+#             */
/*   Updated: 2019/12/15 18:08:36 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	recyrsive_put_room(t_room *current_room, t_way *way)
{
	if (current_room->from_bfs != NULL)
	{
		recyrsive_put_room(current_room->from_bfs, way);
		way->arr_rooms[way->amount_room++] = current_room;
	}
	else
		way->arr_rooms[way->amount_room++] = current_room;
}

static void	put_short_way(t_way *m_insert_in, t_room *i_end)
{
	recyrsive_put_room(i_end, m_insert_in);
	m_insert_in->end = i_end;
}

static void	explore_edges(t_room *m_room, t_room_queue *queue,
								t_boolean *find, t_room *find_room)
{
	int		index_edge;

	index_edge = 0;
	while (index_edge < m_room->amount_edge && !*find)
	{
		if (!m_room->arr_edge[index_edge]->next_room->visited)
		{
			if (m_room->arr_edge[index_edge]->next_room == find_room)
				*find = True;
			else
			{
				push_room_queue(queue, m_room->arr_edge[index_edge]->next_room);
				m_room->arr_edge[index_edge]->next_room->visited = True;
			}
			m_room->arr_edge[index_edge]->next_room->from_bfs = m_room;
		}
		++index_edge;
	}
}

t_way		bfs_algorithm(t_graf *graf)
{
	t_way			short_way;
	t_room			*end;
	t_room			*current_room;
	t_room_queue	room_queue;
	t_boolean		find_room;

	ft_bzero(&short_way, sizeof(t_way));
	ft_bzero(&room_queue, sizeof(t_room_queue));
	end = graf->end;
	push_room_queue(&room_queue, graf->start);
	graf->start->visited = True;
	find_room = False;
	while (room_queue.size && !find_room)
	{
		current_room = pop_room_queue(&room_queue);
		explore_edges(current_room, &room_queue, &find_room, end);
	}
	if (find_room)
		put_short_way(&short_way, end);
	destroy_room_queue(&room_queue);
	return (short_way);
}
