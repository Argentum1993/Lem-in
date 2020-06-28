/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <wmaykit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:31:54 by wmaykit           #+#    #+#             */
/*   Updated: 2019/12/14 18:01:51 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*new_room(char *i_name, int i_index)
{
	t_room	*o_new;

	if (!(o_new = (t_room *)malloc(sizeof(t_room))))
		return (NULL);
	ft_bzero(o_new, sizeof(t_room));
	o_new->name = ft_strdup(i_name);
	o_new->index = i_index;
	return (o_new);
}
