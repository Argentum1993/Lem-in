/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 19:10:35 by astamm            #+#    #+#             */
/*   Updated: 2019/12/15 17:38:41 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	destroy_edges_in_room(t_room *m_del_room)
{
	int		index_edge;

	index_edge = 0;
	while (index_edge < m_del_room->amount_edge)
		ft_memdel((void**)&m_del_room->arr_edge[index_edge++]);
	ft_memdel((void**)&m_del_room->arr_edge);
}

static void	destroy_one_room(t_room **m_del_room)
{
	t_room	*del_room;

	del_room = *m_del_room;
	ft_memdel((void**)&del_room->name);
	if (del_room->in)
		destroy_one_room(&del_room->in);
	if (del_room->out)
		destroy_one_room(&del_room->out);
	destroy_edges_in_room(del_room);
	ft_memdel((void**)m_del_room);
}

void		destroy_graf(t_graf *graf)
{
	int		index_room;

	index_room = -1;
	while (++index_room < graf->amount_rooms)
		destroy_one_room(&graf->rooms[index_room]);
	ft_memdel((void**)&graf->rooms);
}
