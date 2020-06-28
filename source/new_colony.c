/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteration1_new_colony.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 17:51:18 by wmaykit           #+#    #+#             */
/*   Updated: 2019/12/15 13:34:07 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		put_itoa(char *m_str, int i_num)
{
	int			*nums;
	int			num;
	int			curr_index;

	curr_index = 0;
	num = i_num;
	nums = (int[]){10, 100, 1000, 10000, 100000, 1000000, 10000000};
	while (num >= nums[curr_index])
		++curr_index;
	while (curr_index > -1)
	{
		m_str[curr_index--] = num % 10 + '0';
		num /= 10;
	}
}

static int		procedure_mem_allocation_failure(t_ant **m_arry_ants,
															int index_err_ant)
{
	--index_err_ant;
	if (m_arry_ants)
	{
		while (index_err_ant >= 0)
		{
			if (m_arry_ants[index_err_ant])
			{
				free(m_arry_ants[index_err_ant]);
				m_arry_ants[index_err_ant] = NULL;
			}
			--index_err_ant;
		}
	}
	return (FAIL);
}

static void		put_start_end(t_room **m_start, t_room **m_end, t_graf *i_graf)
{
	if (i_graf)
	{
		*m_start = i_graf->start;
		*m_end = i_graf->end;
	}
	else
	{
		*m_start = NULL;
		*m_end = NULL;
	}
}

static int		put_ant_to_arry(t_ant **m_arry_ants, int i_amount_ants,
													t_room *start, t_room *end)
{
	int			index_ant;

	index_ant = 0;
	while (index_ant < i_amount_ants)
	{
		if (!(m_arry_ants[index_ant] = (t_ant *)malloc(sizeof(t_ant))))
			return (procedure_mem_allocation_failure(m_arry_ants, index_ant));
		ft_bzero(m_arry_ants[index_ant], sizeof(t_ant));
		m_arry_ants[index_ant]->way.begin = start;
		m_arry_ants[index_ant]->way.end = end;
		put_itoa(m_arry_ants[index_ant]->name, index_ant + 1);
		++index_ant;
	}
	return (SUCCESS);
}

t_colony		new_colony(int i_amount_ants, t_graf *i_graf)
{
	t_colony	new;
	t_room		*start;
	t_room		*end;

	put_start_end(&start, &end, i_graf);
	ft_bzero(&new, sizeof(t_colony));
	if (!(new.arr_ants = (t_ant **)malloc(sizeof(t_ant*) * i_amount_ants)))
		return (new);
	if (!put_ant_to_arry(new.arr_ants, i_amount_ants, start, end))
	{
		free(new.arr_ants);
		new.arr_ants = NULL;
		return (new);
	}
	new.amount_ants = i_amount_ants;
	return (new);
}
