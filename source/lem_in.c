/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:44:49 by wmaykit           #+#    #+#             */
/*   Updated: 2019/12/17 14:46:54 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		put_options_color_file(t_solution *sol, unsigned int options)
{
	if (options & O_COLOR)
		put_color_to_way(sol);
	if (options & O_FILE)
		write_ready_puth_file(sol, "ways.txt");
}

static void		put_options_screen_matrix(t_graf *graf, unsigned int options)
{
	if (options & O_SCREEN)
		screen_saver();
	if (options & O_MATRIX)
		export_adj_matrix(graf);
}

int				main(int ac, char **av)
{
	t_lem_in		lm;
	t_graf			clean_graf;
	t_solution		solution;
	unsigned int	options;

	options = 0;
	ft_bzero(&lm, sizeof(t_lem_in));
	if (ac > 1)
		options = get_options(ac, av);
	validation(&lm);
	put_options_screen_matrix(&lm.graf, options);
	if (get_index_edge(lm.graf.end, lm.graf.start->index) > -1)
		quick_solve(&lm);
	clean_graf = graf_dup_only_room(&lm.graf);
	solution = get_solution(&lm.graf, &clean_graf, lm.colony.amount_ants);
	put_options_color_file(&solution, options);
	solve(&solution, &lm);
	write_buff(&lm.buf);
	if (options & O_LINES)
		ft_printf("\nGenerate lines = %d\n", solution.amount_lines);
	destroy_solution(&solution);
	destroy_graf(&lm.graf);
	destroy_graf(&clean_graf);
	return (EXIT_SUCCESS);
}
