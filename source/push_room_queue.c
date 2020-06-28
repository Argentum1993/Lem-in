/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_room_queue.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <wmaykit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 11:37:14 by wmaykit           #+#    #+#             */
/*   Updated: 2019/12/14 18:45:17 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	push_room_queue(t_room_queue *m_room_queue, t_room *i_added_room)
{
	t_list_room	*list_room;

	if ((list_room = new_list_room(i_added_room)))
	{
		push_to_room_list(list_room, &m_room_queue->top);
		++m_room_queue->size;
	}
}
