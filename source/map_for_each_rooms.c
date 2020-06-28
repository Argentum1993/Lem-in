/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteration2_map_for_each_rooms.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <wmaykit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 12:10:00 by wmaykit           #+#    #+#             */
/*   Updated: 2019/12/06 20:04:59 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	map_for_each_rooms(t_graf *m_graf, void (*f)(t_room*))
{
	int		index_current_room;

	index_current_room = 0;
	while (index_current_room < m_graf->amount_rooms)
		f(m_graf->rooms[index_current_room++]);
}
