/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteration2_new_fresh_arry_rooms.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <wmaykit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 22:30:49 by wmaykit           #+#    #+#             */
/*   Updated: 2019/12/14 17:59:17 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_graf		new_clean_graf(int amount_room)
{
	t_graf	o_new;

	ft_bzero(&o_new, sizeof(t_graf));
	if (!(o_new.rooms = (t_room **)malloc(sizeof(t_room*) * amount_room)))
		return (o_new);
	ft_bzero(o_new.rooms, sizeof(t_room*) * amount_room);
	return (o_new);
}
