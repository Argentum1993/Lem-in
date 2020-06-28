/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_room_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:46:50 by astamm            #+#    #+#             */
/*   Updated: 2019/12/16 22:00:52 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	put_new_edge(t_edge **arr_edge_in, t_edge *to)
{
	if (to->next_room->out != NULL)
	{
		ft_memdel((void**)arr_edge_in);
		*arr_edge_in = new_edge(to->next_room->out);
	}
	else
	{
		ft_memdel((void**)arr_edge_in);
		*arr_edge_in = new_edge(to->next_room);
	}
}

void		put_room_in(t_room *m_parent)
{
	int		edge;
	int		index;
	char	*name;

	name = ft_strjoin("in_", m_parent->name);
	m_parent->in = new_room(name, m_parent->index);
	ft_strdel(&name);
	m_parent->in->arr_edge = (t_edge**)malloc(sizeof(t_edge*) * 1);
	ft_bzero(m_parent->in->arr_edge, sizeof(t_edge*));
	m_parent->in->amount_edge = 1;
	m_parent->in->parent = m_parent;
	edge = 0;
	while (edge < m_parent->amount_edge)
	{
		index = get_index_edge(m_parent->arr_edge[edge]->next_room,
															m_parent->index);
		if (index >= 0)
			m_parent->arr_edge[edge]->next_room->arr_edge[index]->next_room =
																m_parent->in;
		else
			put_new_edge(m_parent->in->arr_edge, m_parent->arr_edge[edge]);
		edge++;
	}
}
