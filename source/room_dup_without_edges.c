/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_dup_without_edges.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:50:20 by wmaykit           #+#    #+#             */
/*   Updated: 2019/12/14 18:40:12 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	free_mem_on_failure(t_room ***ptr_to_root, int index_fail)
{
	t_room	**rooms;
	int		index_del;

	index_del = index_fail - 1;
	rooms = *ptr_to_root;
	while (index_fail > -1)
	{
		free(rooms[index_del]);
		rooms[index_del] = NULL;
	}
	free(*ptr_to_root);
	*ptr_to_root = NULL;
}

t_room		**room_dup_without_edges(t_room **i_rooms, int amount_rooms)
{
	t_room	**o_dup;
	int		index;

	if (!(o_dup = (t_room **)malloc(sizeof(t_room*) * amount_rooms)))
		return (NULL);
	ft_bzero(o_dup, sizeof(t_room*) * amount_rooms);
	index = 0;
	while (index < amount_rooms)
	{
		if (!(o_dup[index] = new_room(i_rooms[index]->name, index)))
		{
			free_mem_on_failure(&o_dup, index);
			return (NULL);
		}
		++index;
	}
	return (o_dup);
}
