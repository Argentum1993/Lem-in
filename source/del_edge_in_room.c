/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_edge_in_room.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 20:20:29 by wmaykit           #+#    #+#             */
/*   Updated: 2019/12/12 21:01:27 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	del_edge_in_room(t_room *m_from, int index_edge)
{
	free(m_from->arr_edge[index_edge]);
	if (index_edge == m_from->amount_edge - 1)
		m_from->arr_edge[index_edge] = NULL;
	else
	{
		m_from->arr_edge[index_edge] =
								m_from->arr_edge[m_from->amount_edge - 1];
		m_from->arr_edge[m_from->amount_edge - 1] = NULL;
	}
	--m_from->amount_edge;
}
