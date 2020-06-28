/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_screen_saver.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 22:48:58 by astamm            #+#    #+#             */
/*   Updated: 2019/12/16 20:50:32 by astamm           ###   ########.fr       */
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
	viz.y = 40;
	viz.x = 215;
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
	viz.x -= 20;
	vi_print_art("art/FIGHT.txt", "\e[91m", "", viz);
	system("sleep 1.4");
}

void		vi_screen_saver(void)
{
	t_point viz;

	HIDE_CURSOR;
	CLEAR;
	viz.y = 5;
	viz.x = 150;
	vi_print_art("art/lem_in.txt", "", "sleep 0.15", viz);
	GOTOYX(26, 210);
	system("sleep 0.65");
	ft_printf("\e[36mThis is not Fillit !\e[0m");
	viz.y = 95;
	viz.x = 155;
	system("sleep 0.99");
	vi_print_art("art/created.txt", "", "sleep 0.3", viz);
	system("sleep 0.7");
	vi_сountdown(viz);
	VISIBLE_CURSOR;
}
