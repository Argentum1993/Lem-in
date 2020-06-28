/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_puth_all_ant_file.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 21:37:05 by wmaykit           #+#    #+#             */
/*   Updated: 2019/12/17 15:03:28 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <fcntl.h>
#include <stdio.h>

void		write_puth_all_ant_file(t_colony *i_colony, char *name_file)
{
	int		fd;
	int		index_ant;
	int		index_room;

	index_ant = 0;
	fd = open(name_file, O_WRONLY | O_TRUNC | O_CREAT, 511);
	while (index_ant < i_colony->amount_ants)
	{
		index_room = 0;
		dprintf(fd, "Ant [%s]\n", i_colony->arr_ants[index_ant]->name);
		while (index_room <= i_colony->arr_ants[index_ant]->way.amount_room - 1)
		{
			dprintf(fd, "[%s] -> ", i_colony->arr_ants[index_ant]->
											way.arr_rooms[index_room]->name);
			++index_room;
		}
		dprintf(fd, "len %d", i_colony->arr_ants[index_ant]->way.amount_room
																		- 1);
		dprintf(fd, "\n\n");
		++index_ant;
	}
	close(fd);
}

void		write_ready_puth_file(t_solution *f, char *name_file)
{
	int		fd;
	int		index_room;
	int		index_way;

	fd = open(name_file, O_WRONLY | O_TRUNC | O_CREAT, 511);
	index_way = -1;
	while (++index_way < f->amount_ways)
	{
		index_room = -1;
		dprintf(fd, "Way [%d]\n", index_way + 1);
		while (++index_room <= f->ready_ways[index_way].way.amount_room - 1)
		{
			dprintf(fd, "[%s] -> ", f->ready_ways[index_way].
					way.arr_rooms[index_room]->name);
		}
		dprintf(fd, "len way = %d", f->ready_ways[index_way].way.amount_room
																		- 1);
		dprintf(fd, " # ants = %d", f->ready_ways[index_way].amount_ants);
		dprintf(fd, "\n\n");
	}
	close(fd);
}
