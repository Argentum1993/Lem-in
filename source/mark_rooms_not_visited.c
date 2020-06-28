/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteration2_mark_rooms_not_visited.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 12:06:56 by wmaykit           #+#    #+#             */
/*   Updated: 2019/12/14 00:38:45 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		mark_rooms_not_visited(t_room *m_room)
{
	m_room->visited = False;
	if (m_room->in)
		m_room->in->visited = False;
	if (m_room->out)
		m_room->out->visited = False;
}
