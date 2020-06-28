/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteration2_reverse_edge.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 10:57:46 by wmaykit           #+#    #+#             */
/*   Updated: 2019/12/14 12:21:38 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		reverse_edge(t_way *m_way)
{
	int		index_to_room;
	int		index_from_room;
	t_room	**rooms;

	index_from_room = 0;
	rooms = m_way->arr_rooms;
	index_to_room = index_from_room + 1;
	while (index_to_room < m_way->amount_room)
	{
		if (!rooms[index_from_room]->parent)
			del_edge(rooms[index_from_room], rooms[index_to_room]);
		++index_from_room;
		++index_to_room;
	}
}
