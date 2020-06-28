/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_solution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 01:59:03 by wmaykit           #+#    #+#             */
/*   Updated: 2019/12/16 16:37:41 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	destroy_ways(t_solution *solution)
{
	t_ready_ways	*ways;
	int				index_way;

	ways = solution->ready_ways;
	index_way = 0;
	while (index_way < solution->amount_ways)
		ft_memdel((void**)&ways[index_way++].way.color);
}

void		destroy_solution(t_solution *solution)
{
	destroy_ways(solution);
}
