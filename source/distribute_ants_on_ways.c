/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribute_ants_on_ways.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 05:55:53 by astamm            #+#    #+#             */
/*   Updated: 2019/12/16 16:38:05 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	distribute_ants_add_if(t_solution *solution, int *amoun_ways,
																	int *max)
{
	*amoun_ways += 1;
	if (*amoun_ways >= solution->amount_ways)
	{
		*max += 1;
		if (*amoun_ways > solution->amount_ways)
			*amoun_ways -= 1;
	}
	else
		*max = solution->ready_ways[*amoun_ways].way.amount_room - 1;
}

static void	reculc(int *amount_ants_in_way, int *sum, int *amount_ants)
{
	++(*amount_ants_in_way);
	++(*sum);
	--(*amount_ants);
}

static void	put_copy_ways_to_solution(t_solution *solution,
													t_arry_way *no_ntrs_ways)
{
	int	i;

	i = 0;
	while (i < no_ntrs_ways->amount)
	{
		solution->ready_ways[i].way = no_ntrs_ways->ways[i];
		i++;
	}
	solution->amount_ways = no_ntrs_ways->amount;
}

static void	put_amount_lines(t_solution *solution)
{
	solution->have_empty_way =
solution->ready_ways[solution->amount_ways - 1].amount_ants == 0 ? True : False;
	solution->amount_lines = ((solution->ready_ways[0].way.amount_room - 1) +
									solution->ready_ways[0].amount_ants) - 1;
}

t_solution	distribute_ants_on_ways(t_arry_way *no_ntrs_ways, int amount_ants)
{
	int			i;
	int			max;
	int			amount_ways;
	int			sum;
	t_solution	solution;

	put_copy_ways_to_solution(&solution, no_ntrs_ways);
	amount_ways = 1;
	max = solution.ready_ways[amount_ways].way.amount_room - 1;
	while (amount_ants != 0 && amount_ways <= solution.amount_ways)
	{
		i = 0;
		while (i < amount_ways && amount_ants != 0)
		{
			sum = solution.ready_ways[i].way.amount_room - 1 +
											solution.ready_ways[i].amount_ants;
			if (sum < max)
				reculc(&solution.ready_ways[i].amount_ants, &sum, &amount_ants);
			if (++i >= amount_ways && sum < max)
				i = 0;
		}
		distribute_ants_add_if(&solution, &amount_ways, &max);
	}
	put_amount_lines(&solution);
	return (solution);
}
