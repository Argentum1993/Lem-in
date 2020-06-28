/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_ant_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 11:15:56 by wmaykit           #+#    #+#             */
/*   Updated: 2019/12/14 21:15:57 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	recursive_delete_ant_list(t_list_ant *m_del_list)
{
	if (!m_del_list)
		return ;
	else
	{
		recursive_delete_ant_list(m_del_list->next);
		free(m_del_list);
		m_del_list = NULL;
	}
}

void		destroy_ant_list(t_list_ant **m_top)
{
	recursive_delete_ant_list(*m_top);
	*m_top = NULL;
}
