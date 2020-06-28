/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_in_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 16:44:44 by wmaykit           #+#    #+#             */
/*   Updated: 2019/11/29 09:49:22 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	push_to_in_end(t_ants_queue *m_ants_queue, t_list_ant *m_list_ant)
{
	if (m_list_ant && m_ants_queue->amount_ants_in_path > 0)
	{
		cut_list_ant(m_list_ant, &m_ants_queue->ants_in_path);
		--m_ants_queue->amount_ants_in_path;
		push_to_ant_list(m_list_ant, &m_ants_queue->ants_in_end);
		++m_ants_queue->amount_ants_in_end;
	}
}
