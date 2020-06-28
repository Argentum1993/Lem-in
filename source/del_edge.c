/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteration2_del_edge.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <wmaykit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 11:10:54 by wmaykit           #+#    #+#             */
/*   Updated: 2019/12/14 17:58:59 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	get_index_edge_by_ptr(t_room *i_from, t_room *i_to)
{
	int		o_index_edge;

	o_index_edge = 0;
	while (o_index_edge < i_from->amount_edge)
	{
		if (i_from->arr_edge[o_index_edge]->next_room == i_to)
			return (o_index_edge);
		++o_index_edge;
	}
	return (-1);
}

void		del_edge(t_room *m_from, t_room *i_to)
{
	int		index_del_edge;
	int		index_last_edge;

	if ((index_del_edge = get_index_edge_by_ptr(m_from, i_to)) >= 0)
	{
		index_last_edge = m_from->amount_edge - 1;
		free(m_from->arr_edge[index_del_edge]);
		m_from->arr_edge[index_del_edge] = NULL;
		m_from->arr_edge[index_del_edge] = m_from->arr_edge[index_last_edge];
		--m_from->amount_edge;
	}
}
