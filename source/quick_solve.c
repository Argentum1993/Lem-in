/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_solve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 00:21:27 by wmaykit           #+#    #+#             */
/*   Updated: 2019/12/17 01:16:52 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	quick_solve(t_lem_in *lem_in)
{
	int ant_name;

	ant_name = 1;
	while (ant_name <= lem_in->colony.amount_ants)
	{
		ft_printf("L%d-%s", ant_name, lem_in->graf.end->name);
		if (ant_name != lem_in->colony.amount_ants)
			ft_printf(" ");
		++ant_name;
	}
	ft_printf("\n");
	exit(EXIT_SUCCESS);
}
