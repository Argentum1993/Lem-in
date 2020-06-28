/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graf_dup_only_room.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 17:17:05 by wmaykit           #+#    #+#             */
/*   Updated: 2019/12/12 22:56:18 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_graf	graf_dup_only_room(t_graf *i_from)
{
	t_graf	o_new;

	ft_bzero(&o_new, sizeof(t_graf));
	if ((o_new.rooms = room_dup_without_edges(i_from->rooms,
														i_from->amount_rooms)))
	{
		o_new.amount_rooms = i_from->amount_rooms;
		o_new.start = o_new.rooms[i_from->start->index];
		o_new.end = o_new.rooms[i_from->end->index];
	}
	return (o_new);
}
