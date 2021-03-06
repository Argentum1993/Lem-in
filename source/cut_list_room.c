/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_list_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <wmaykit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:08:33 by wmaykit           #+#    #+#             */
/*   Updated: 2019/12/14 21:16:23 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		cut_from_two_item_list(t_list_room *m_cut_list,
													t_list_room **m_top_list)
{
	if (!m_cut_list->next)
	{
		(*m_top_list)->next = NULL;
		(*m_top_list)->prev = NULL;
	}
	else
	{
		(*m_top_list) = (*m_top_list)->next;
		(*m_top_list)->next = NULL;
		(*m_top_list)->prev = NULL;
	}
}

static void		cut_from_more_two_item_list(t_list_room *m_cut_list,
													t_list_room **m_top_list)
{
	if (m_cut_list == (*m_top_list))
	{
		(*m_top_list) = (*m_top_list)->next;
		(*m_top_list)->prev = m_cut_list->prev;
	}
	else if (m_cut_list->next)
	{
		m_cut_list->prev->next = m_cut_list->next;
		m_cut_list->next->prev = m_cut_list->prev;
	}
	else
	{
		(*m_top_list)->prev = m_cut_list->prev;
		m_cut_list->prev->next = NULL;
	}
}

void			cut_list_room(t_list_room *m_cut_list, t_list_room **m_top_list)
{
	if (!(*m_top_list)->prev)
		*m_top_list = NULL;
	else if ((*m_top_list)->prev == (*m_top_list)->next)
		cut_from_two_item_list(m_cut_list, m_top_list);
	else
		cut_from_more_two_item_list(m_cut_list, m_top_list);
	m_cut_list->next = NULL;
	m_cut_list->prev = NULL;
}
