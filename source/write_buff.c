/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_buff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 21:12:30 by wmaykit           #+#    #+#             */
/*   Updated: 2019/11/08 10:37:35 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	write_buff(t_lm_buf *m_buf)
{
	write(1, m_buf->begin, m_buf->current_position - m_buf->begin);
	m_buf->current_position = m_buf->begin;
}
