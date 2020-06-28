/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_colony.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 19:45:29 by wmaykit           #+#    #+#             */
/*   Updated: 2019/11/28 19:19:12 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		destroy_colony(t_colony *m_colony)
{
	t_ant	**ants;
	int		index_ant;

	index_ant = 0;
	if ((ants = m_colony->arr_ants))
	{
		while (index_ant < m_colony->amount_ants)
		{
			if (ants[index_ant])
			{
				free(ants[index_ant]);
				ants[index_ant] = NULL;
			}
			++index_ant;
		}
		free(m_colony->arr_ants);
		m_colony->arr_ants = NULL;
	}
}
