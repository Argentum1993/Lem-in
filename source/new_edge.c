/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_edge.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <wmaykit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:49:29 by wmaykit           #+#    #+#             */
/*   Updated: 2019/12/14 18:00:24 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_edge		*new_edge(t_room *i_to_this_room)
{
	t_edge	*o_new;

	if (!(o_new = (t_edge *)malloc(sizeof(t_edge))))
		return (NULL);
	ft_bzero(o_new, sizeof(t_edge));
	o_new->next_room = i_to_this_room;
	return (o_new);
}
