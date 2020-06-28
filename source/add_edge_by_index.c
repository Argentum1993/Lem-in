/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_edge_by_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 19:31:56 by wmaykit           #+#    #+#             */
/*   Updated: 2019/12/15 18:37:36 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_edge_by_index(t_graf *m_graf, int index_from, int index_to)
{
	t_edge	**save_edges;
	t_edge	**new_edges;

	new_edges = NULL;
	save_edges = m_graf->rooms[index_from]->arr_edge;
	if (m_graf->rooms[index_from]->amount_edge > 0)
	{
		if (!(new_edges = (t_edge **)malloc(sizeof(t_edge*) *
						(m_graf->rooms[index_from]->amount_edge + 1))))
			return ;
		ft_memcpy(new_edges, save_edges, sizeof(t_edge*) *
									m_graf->rooms[index_from]->amount_edge);
		ft_memdel((void**)&save_edges);
	}
	else if (!(new_edges = (t_edge **)malloc(sizeof(t_edge*))))
		return ;
	if (!(new_edges[m_graf->rooms[index_from]->amount_edge] =
											new_edge(m_graf->rooms[index_to])))
		return ;
	ft_memdel((void**)&save_edges);
	m_graf->rooms[index_from]->arr_edge = new_edges;
	++m_graf->rooms[index_from]->amount_edge;
}
