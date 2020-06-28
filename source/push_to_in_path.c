/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_in_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 12:12:26 by wmaykit           #+#    #+#             */
/*   Updated: 2019/12/14 21:17:59 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	push_to_in_path(t_ants_queue *m_ants_queue, t_list_ant *m_list_ant)
{
	if (m_list_ant && m_ants_queue->amount_ants_in_start > 0)
	{
		cut_list_ant(m_list_ant, &m_ants_queue->ants_in_start);
		--m_ants_queue->amount_ants_in_start;
		push_to_ant_list(m_list_ant, &m_ants_queue->ants_in_path);
		++m_ants_queue->amount_ants_in_path;
	}
}
