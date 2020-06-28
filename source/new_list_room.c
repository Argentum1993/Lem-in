/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_list_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <wmaykit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 11:29:59 by wmaykit           #+#    #+#             */
/*   Updated: 2019/12/05 16:39:46 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list_room		*new_list_room(t_room *i_room)
{
	t_list_room	*o_new;

	if (!(o_new = (t_list_room *)malloc(sizeof(t_list_room))))
		return (NULL);
	ft_bzero(o_new, sizeof(t_list_room));
	o_new->room = i_room;
	return (o_new);
}
