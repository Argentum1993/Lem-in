/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 19:52:49 by wmaykit           #+#    #+#             */
/*   Updated: 2019/12/17 01:18:18 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	go_to_next_room(t_ant *m_ant)
{
	m_ant->current_room->index_ant = 0;
	m_ant->current_room = m_ant->path->arr_rooms[++m_ant->index_current_room];
	m_ant->current_room->index_ant = 1;
}

static void	move_ant_in_path(t_ants_queue *ants_queue)
{
	t_list_ant		*current_ant;

	current_ant = ants_queue->ants_in_path;
	while (current_ant)
	{
		go_to_next_room(current_ant->ant);
		current_ant = current_ant->next;
	}
}

static void	move_ant_in_start(t_ants_queue *ants_queue, t_solution *solution)
{
	t_list_ant		*curr_ant;
	t_list_ant		*next_ant;
	int				index_path;

	index_path = 0;
	if (!(curr_ant = ants_queue->ants_in_start) || !curr_ant->ant)
		return ;
	while (index_path < solution->amount_ways && curr_ant)
	{
		if (solution->ready_ways[index_path].way.arr_rooms[1]->index_ant == 0 &&
			solution->ready_ways[index_path].amount_ants > 0)
		{
			curr_ant->ant->path = &solution->ready_ways[index_path].way;
			curr_ant->ant->current_room = curr_ant->ant->path->arr_rooms[0];
			go_to_next_room(curr_ant->ant);
			next_ant = curr_ant->next;
			push_to_in_path(ants_queue, curr_ant);
			curr_ant = next_ant;
			--solution->ready_ways[index_path].amount_ants;
		}
		++index_path;
	}
}

static void	add_result_to_buf_and_push_to_end(t_ants_queue *ants_queue,
																t_lm_buf *buf)
{
	t_list_ant		*current_ant;
	t_list_ant		*next_ant;

	current_ant = ants_queue->ants_in_path;
	while (current_ant)
	{
		next_ant = current_ant->next;
		if (current_ant->ant->path->color)
			add_to_buff(buf, current_ant->ant->path->color);
		add_to_buff(buf, "L");
		add_to_buff(buf, current_ant->ant->name);
		add_to_buff(buf, "-");
		add_to_buff(buf, current_ant->ant->current_room->name);
		if (current_ant->next)
			add_to_buff(buf, " ");
		if (current_ant->ant->current_room ==
				current_ant->ant->path->arr_rooms[
				current_ant->ant->path->amount_room - 1])
			push_to_in_end(ants_queue, current_ant);
		if (current_ant->ant->path->color)
			add_to_buff(buf, "\e[0m");
		current_ant = next_ant;
	}
}

void		solve(t_solution *m_result, t_lem_in *lem_in)
{
	t_ants_queue	ant_queue;
	int				status;
	int				debug_caunter;

	status = STATUS_NORMAL;
	debug_caunter = 0;
	lem_in->colony = new_colony(lem_in->colony.amount_ants, &lem_in->graf);
	ant_queue = new_ants_queue(&lem_in->colony, &status);
	while (ant_queue.amount_ants_in_end <
						lem_in->colony.amount_ants && debug_caunter++ < 1000)
	{
		move_ant_in_path(&ant_queue);
		move_ant_in_start(&ant_queue, m_result);
		add_result_to_buf_and_push_to_end(&ant_queue, &lem_in->buf);
		add_to_buff(&lem_in->buf, "\n");
	}
	destroy_ants_queue(&ant_queue);
	destroy_colony(&lem_in->colony);
}
