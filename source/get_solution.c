/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_solution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 05:29:09 by astamm            #+#    #+#             */
/*   Updated: 2019/12/17 15:02:10 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_solution		get_solution(t_graf *graf, t_graf *clean_graf, int amount_ants)
{
	t_way		short_way;
	t_arry_way	no_ntrs_ways;
	t_solution	best_solution;
	t_solution	curent_solution;

	ft_bzero(&curent_solution, sizeof(t_solution) * 2);
	short_way.amount_room = 1;
	while (short_way.amount_room > 0)
	{
		if (best_solution.amount_lines > curent_solution.amount_lines ||
				best_solution.amount_ways <= 0)
			best_solution = curent_solution;
		short_way = bfs_algorithm(graf);
		push_way_to_clean_graf(clean_graf, &short_way);
		no_ntrs_ways = get_no_intersections_ways(clean_graf);
		curent_solution = distribute_ants_on_ways(&no_ntrs_ways, amount_ants);
		map_for_each_rooms(graf, mark_rooms_not_visited);
		reverse_edge(&short_way);
		split_rooms_in_way(&short_way);
	}
	return (best_solution);
}
