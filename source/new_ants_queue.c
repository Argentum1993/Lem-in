/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ants_queue.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 22:03:28 by wmaykit           #+#    #+#             */
/*   Updated: 2019/12/14 18:53:54 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_list_ant	*new_list_ant(t_ant *i_entry_ant)
{
	t_list_ant		*o_new;

	if (!(o_new = (t_list_ant *)malloc(sizeof(t_list_ant))))
		return (NULL);
	ft_bzero(o_new, sizeof(t_list_ant));
	o_new->ant = i_entry_ant;
	return (o_new);
}

static int			add_new_list_ant(t_ant *i_insert_ant,
														t_list_ant **m_top_list)
{
	t_list_ant		*o_new;

	if ((o_new = new_list_ant(i_insert_ant)) == NULL)
	{
		destroy_ant_list(m_top_list);
		return (FAIL);
	}
	push_to_ant_list(o_new, m_top_list);
	return (SUCCESS);
}

t_ants_queue		new_ants_queue(t_colony *i_colony, int *m_stat)
{
	t_ants_queue	o_new;
	t_ant			**ants;
	int				index_ant;

	ft_bzero(&o_new, sizeof(t_ants_queue));
	ants = i_colony->arr_ants;
	index_ant = 0;
	while (index_ant < i_colony->amount_ants)
	{
		if (!add_new_list_ant(ants[index_ant], &o_new.ants_in_start))
		{
			*m_stat = MALLOC_ERROR;
			return (o_new);
		}
		++index_ant;
	}
	o_new.amount_ants_in_start = i_colony->amount_ants;
	return (o_new);
}
