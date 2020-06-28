/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_room_queue.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 17:57:08 by wmaykit           #+#    #+#             */
/*   Updated: 2019/12/15 20:47:14 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	recyrsive_destroy_lists(t_list_room *del_list)
{
	if (del_list)
	{
		recyrsive_destroy_lists(del_list->next);
		ft_memdel((void**)&del_list);
	}
}

void		destroy_room_queue(t_room_queue *m_queue)
{
	recyrsive_destroy_lists(m_queue->top);
	m_queue->top = NULL;
	m_queue->size = 0;
}
