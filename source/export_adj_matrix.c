/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_adj_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:02:59 by wmaykit           #+#    #+#             */
/*   Updated: 2019/12/17 14:47:01 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "lem_in.h"
#define EXPORT_FILE "matrix.txt"
#define ERROR_MALLOC 1
#define ERROR_MALLOC 1
#define NO_ERROR 0

static int		get_index_room(t_room **i_rooms, t_room *i_index_find)
{
	int		o_index_room;

	o_index_room = 0;
	while (i_rooms[o_index_room])
	{
		if (i_rooms[o_index_room] == i_index_find)
			return (o_index_room);
		++o_index_room;
	}
	return (-1);
}

static void		fill_matrix(int **m_adj_matrix, t_graf *i_graf)
{
	int		index_edge;
	int		index_from;
	int		index_to;

	index_from = 0;
	while (index_from < i_graf->amount_rooms)
	{
		index_edge = 0;
		while (index_edge < i_graf->rooms[index_from]->amount_edge)
		{
			if ((index_to = get_index_room(i_graf->rooms,
			i_graf->rooms[index_from]->arr_edge[index_edge]->next_room)) > -1)
			{
				m_adj_matrix[index_from][index_to] = 1;
				m_adj_matrix[index_to][index_from] = 1;
			}
			++index_edge;
		}
		++index_from;
	}
}

static void		export_matrix_to_file(int **i_matrix, int length_i,
																int length_j)
{
	int		file_fd;
	int		index_i;
	int		index_j;

	if ((file_fd = open(EXPORT_FILE, O_WRONLY | O_TRUNC | O_CREAT, 511)) < 0)
		ft_printf("Error open file [%s]", EXPORT_FILE);
	else
	{
		index_i = 0;
		while (index_i < length_i)
		{
			index_j = 0;
			while (index_j < length_j)
			{
				dprintf(file_fd, "%d", i_matrix[index_i][index_j]);
				if (index_j != length_j - 1)
					dprintf(file_fd, ", ");
				++index_j;
			}
			dprintf(file_fd, "\n");
			++index_i;
		}
	}
	close(file_fd);
}

static void		dell_adj_matrix(int **m_matrix, int i_lenth_edge)
{
	int		index_i;

	index_i = i_lenth_edge - 1;
	while (index_i > -1)
	{
		ft_bzero(m_matrix[index_i], sizeof(int) * i_lenth_edge);
		free(m_matrix[index_i--]);
	}
	if (m_matrix)
	{
		ft_bzero(m_matrix, sizeof(int*) * i_lenth_edge);
		free(m_matrix);
	}
}

void			export_adj_matrix(t_graf *i_graf)
{
	int		**adj_matrix;
	int		index_room;

	if ((adj_matrix = (int **)malloc(sizeof(int*) * i_graf->amount_rooms)))
	{
		index_room = 0;
		while (index_room < i_graf->amount_rooms)
		{
			if (!(adj_matrix[index_room] =
						(int *)malloc(sizeof(int) * i_graf->amount_rooms)))
				ft_printf("(line %d)Error add mmemory *", __LINE__);
			else
				ft_bzero(adj_matrix[index_room],
										sizeof(int) * i_graf->amount_rooms);
			++index_room;
		}
		fill_matrix(adj_matrix, i_graf);
		export_matrix_to_file(adj_matrix, i_graf->amount_rooms,
														i_graf->amount_rooms);
		dell_adj_matrix(adj_matrix, i_graf->amount_rooms);
	}
}
