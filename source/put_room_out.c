/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_room_out.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:46:48 by astamm            #+#    #+#             */
/*   Updated: 2019/12/16 22:00:17 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			get_index_edge(t_room *from_room, int index_desired_room)
{
	int		index_edge;

	index_edge = 0;
	while (index_edge < from_room->amount_edge)
	{
		if (from_room->arr_edge[index_edge]->next_room->index ==
															index_desired_room)
			return (index_edge);
		index_edge++;
	}
	return (-1);
}

void		put_room_out(t_room *m_parent)
{
	int		index_edge;
	int		amount_record_edges;
	char	*name;

	name = ft_strjoin("out_", m_parent->name);
	m_parent->out = new_room(name, m_parent->index);
	ft_strdel(&name);
	m_parent->out->arr_edge = (t_edge**)malloc(sizeof(t_edge*) *
														m_parent->amount_edge);
	index_edge = 0;
	amount_record_edges = 0;
	while (index_edge < m_parent->amount_edge)
	{
		if ((get_index_edge(m_parent->arr_edge[index_edge]->next_room,
														m_parent->index)) >= 0)
			m_parent->out->arr_edge[amount_record_edges++] =
							new_edge(m_parent->arr_edge[index_edge]->next_room);
		index_edge++;
	}
	m_parent->out->arr_edge[amount_record_edges++] = new_edge(m_parent->in);
	m_parent->out->amount_edge = amount_record_edges;
	m_parent->out->parent = m_parent;
}
