/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_room_queue.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 13:59:01 by wmaykit           #+#    #+#             */
/*   Updated: 2019/12/06 12:02:04 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*pop_room_queue(t_room_queue *m_room_queue)
{
	t_list_room		*top_list;
	t_room			*o_room;

	if (m_room_queue->size > 0)
	{
		top_list = m_room_queue->top;
		cut_list_room(top_list, &m_room_queue->top);
		--m_room_queue->size;
		o_room = top_list->room;
		free(top_list);
		return (o_room);
	}
	return (NULL);
}
