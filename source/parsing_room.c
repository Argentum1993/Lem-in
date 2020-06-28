/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 20:58:47 by astamm            #+#    #+#             */
/*   Updated: 2019/12/16 15:16:34 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	parsing_start_end(t_lem_in *lm, t_valid_pars *vp)
{
	if (vp->start == 1)
	{
		lm->graf.start = lm->graf.rooms[vp->index_current_room];
		vp->start = 0;
	}
	else if (vp->end == 1)
	{
		lm->graf.end = lm->graf.rooms[vp->index_current_room];
		vp->end = 0;
	}
}

static void	assign_name_x_y(char *str, char **name, t_point *coord)
{
	int	k;

	k = 0;
	while (str[k] != ' ')
		k++;
	*name = ft_strsub(str, 0, k);
	coord->x = ft_atoi(str + ++k);
	while (str[k] != ' ')
		k++;
	coord->y = ft_atoi(str + ++k);
}

static void	check_duplicate_name(char *room, t_graf graf, t_valid_pars *vp)
{
	int		i;
	t_point	coord;
	size_t	len_name;
	char	*name_room;

	assign_name_x_y(room, &name_room, &coord);
	len_name = ft_strlen(name_room);
	i = 0;
	while (i < graf.amount_rooms && graf.rooms[i] != NULL)
	{
		if (ft_strncmp(name_room, graf.rooms[i]->name, len_name) == 0 ||
		(coord.x == graf.rooms[i]->coordinates.x &&
		coord.y == graf.rooms[i]->coordinates.y))
		{
			ft_memdel((void**)&name_room);
			free_map_rooms(vp);
			ft_memdel((void**)&vp->list_edges);
			if (coord.x == graf.rooms[i]->coordinates.x &&
										coord.y == graf.rooms[i]->coordinates.y)
				error_processing("Duplicate coordinates in the room");
			error_processing("Duplicate room name");
		}
		i++;
	}
	ft_memdel((void**)&name_room);
}

static void	parsing_room(t_lem_in *lm, t_valid_pars *vp)
{
	check_duplicate_name(vp->map_rooms->list->str, lm->graf, vp);
	vp->index_current_room++;
	lm->graf.rooms[vp->index_current_room] = (t_room*)malloc(sizeof(t_room));
	ft_bzero((void*)lm->graf.rooms[vp->index_current_room], sizeof(t_room));
	assign_name_x_y(vp->map_rooms->list->str,
		&lm->graf.rooms[vp->index_current_room]->name,
		&lm->graf.rooms[vp->index_current_room]->coordinates);
	lm->graf.rooms[vp->index_current_room]->index = vp->index_current_room;
	lm->graf.rooms[vp->index_current_room]->index_ant = -1;
	parsing_start_end(lm, vp);
}

int			parsing_begin_room(t_lem_in *lm, t_valid_pars *vp)
{
	if (ft_strcmp(vp->map_rooms->list->str, "##start") == 0)
	{
		if (vp->end == 1)
			error_repeat_commands(vp);
		vp->start = 1;
	}
	else if (ft_strcmp(vp->map_rooms->list->str, "##end") == 0)
	{
		if (vp->start == 1)
			error_repeat_commands(vp);
		vp->end = 1;
	}
	else if (vp->start == 0 && vp->end == 0 &&
											vp->map_rooms->list->str[0] == '#')
		return (0);
	else if (vp->map_rooms->list->str[0] == '#' &&
											vp->map_rooms->list->str[1] != '#')
		return (0);
	else
		parsing_room(lm, vp);
	return (1);
}
