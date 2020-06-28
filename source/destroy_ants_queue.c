/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_ants_queue.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 12:06:47 by wmaykit           #+#    #+#             */
/*   Updated: 2019/11/28 12:11:14 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	destroy_ants_queue(t_ants_queue *m_ants_queue)
{
	destroy_ant_list(&m_ants_queue->ants_in_start);
	destroy_ant_list(&m_ants_queue->ants_in_path);
	destroy_ant_list(&m_ants_queue->ants_in_end);
	ft_bzero(m_ants_queue, sizeof(t_ants_queue));
}
