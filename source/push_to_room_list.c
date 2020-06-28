/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_room_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 14:48:06 by wmaykit           #+#    #+#             */
/*   Updated: 2019/12/05 14:07:08 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	push_to_room_list(t_list_room *m_insert_list, t_list_room **m_top_list)
{
	if (!(*m_top_list))
		(*m_top_list) = m_insert_list;
	else if ((*m_top_list)->prev == NULL)
	{
		(*m_top_list)->next = m_insert_list;
		(*m_top_list)->prev = m_insert_list;
		m_insert_list->prev = (*m_top_list);
	}
	else
	{
		(*m_top_list)->prev->next = m_insert_list;
		m_insert_list->prev = (*m_top_list)->prev;
		(*m_top_list)->prev = m_insert_list;
	}
}
