/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index_room.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <wmaykit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:49:37 by wmaykit           #+#    #+#             */
/*   Updated: 2019/12/14 17:56:18 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		get_index_room(t_graf *i_graf, t_room *i_this_room)
{
	int		o_index_room;

	o_index_room = 0;
	while (o_index_room < i_graf->amount_rooms &&
			i_graf->rooms[o_index_room] != i_this_room)
		++o_index_room;
	if (i_graf->rooms[o_index_room] == i_this_room)
		return (o_index_room);
	return (-1);
}
