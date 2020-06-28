/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_color_to_way.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 21:34:33 by wmaykit           #+#    #+#             */
/*   Updated: 2019/12/15 22:32:22 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	put_color_to_way(t_solution *solution)
{
	int				index_way;
	char			*num_color;
	char			color[13];
	char			*insert;
	t_ready_ways	*ways;

	index_way = 0;
	ways = solution->ready_ways;
	ft_bzero(color, 13);
	ft_strcpy(color, "\e[38;5;");
	insert = color + 7;
	while (index_way < solution->amount_ways)
	{
		num_color = ft_itoa(index_way + 1);
		ft_strcpy(insert, num_color);
		ft_memdel((void**)&num_color);
		ft_strlcat(insert, "m", 4);
		ways[index_way].way.color = ft_strdup(color);
		ft_bzero(insert, 5);
		++index_way;
	}
}
