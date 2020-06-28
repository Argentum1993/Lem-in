/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_saver.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 22:48:58 by astamm            #+#    #+#             */
/*   Updated: 2019/12/17 01:06:57 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	vi_print_art(char *name, char *atribut, char *delay, t_point viz)
{
	int fd;

	fd = open(name, O_RDONLY);
	ft_printf("%s", atribut);
	while ((get_next_line(fd, &name)) > 0)
	{
		GOTOYX(viz.y++, viz.x);
		ft_printf("%s\n", name);
		system(delay);
		free(name);
	}
	RESET_COLOR;
	close(fd);
}

static void	ps_vis_clear_line(t_point viz, int height)
{
	int i;

	i = 1;
	while (i <= height)
	{
		GOTOYX(viz.y++, viz.x);
		ft_printf("\e[2K");
		i++;
	}
}

static void	vi_сountdown(t_point viz)
{
	viz.y = 37;
	viz.x = 205;
	system("sleep 0.70");
	vi_print_art("art/3.txt", "\e[32m", "", viz);
	system("sleep 1.00");
	ps_vis_clear_line(viz, 16);
	vi_print_art("art/2.txt", "\e[35m", "", viz);
	system("sleep 1.00");
	ps_vis_clear_line(viz, 16);
	vi_print_art("art/1.txt", "\e[93m", "", viz);
	system("sleep 1.00");
	ps_vis_clear_line(viz, 16);
	viz.y += 5;
	viz.x -= 25;
	vi_print_art("art/run.txt", "\e[91m", "", viz);
	system("sleep 1.1");
}

static void	run_ants(void)
{
	t_point ant_1;
	t_point ant_2;

	ant_1.y = 30;
	ant_1.x = 271;
	ant_2.y = 55;
	ant_2.x = 271;
	while (ant_1.x != 140)
	{
		vi_print_art("art/ant_1.txt", "", "", ant_1);
		vi_print_art("art/ant_2.txt", "", "", ant_2);
		ant_1.x--;
		ant_2.x--;
	}
}

void		screen_saver(void)
{
	t_point viz;

	HIDE_CURSOR;
	CLEAR;
	viz.y = 2;
	viz.x = 140;
	vi_print_art("art/lem_in.txt", "", "sleep 0.13", viz);
	system("sleep 0.4");
	viz.y = 75;
	viz.x = 150;
	system("sleep 0.4");
	vi_print_art("art/created.txt", "", "sleep 0.17", viz);
	system("sleep 0.42");
	vi_сountdown(viz);
	run_ants();
	system("sleep 1.3");
	CLEAR;
	GO_LAST_LINE;
	VISIBLE_CURSOR;
}
