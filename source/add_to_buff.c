/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_buff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 19:05:27 by wmaykit           #+#    #+#             */
/*   Updated: 2019/11/08 10:36:52 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_to_buff(t_lm_buf *m_buf, char *i_data)
{
	while (*i_data)
	{
		if (m_buf->current_position >= m_buf->end_buf)
			write_buff(m_buf);
		*m_buf->current_position++ = *i_data++;
	}
}
