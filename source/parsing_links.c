/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_links.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 21:34:05 by astamm            #+#    #+#             */
/*   Updated: 2019/12/17 15:04:54 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			search_index_room(t_graf *graf, t_valid_pars *vp, char *name_room)
{
	int index_room;

	index_room = 0;
	while (index_room < graf->amount_rooms)
	{
		if (ft_strcmp(name_room, graf->rooms[index_room]->name) == 0)
		{
			vp->list_edges->amount_edges++;
			return (index_room);
		}
		else
			index_room++;
	}
	return (-1);
}

int			check_second_link(t_valid_pars *vp, t_graf *graf, char *name_room,
																		int i)
{
	char	*name_neighbour;
	int		index_neighbour_room;

	if (ft_strcmp(vp->map_edges->list->str + ++i, name_room) == 0)
	{
		name_neighbour = ft_strsub(vp->map_edges->list->str, 0, i - 1);
		index_neighbour_room = search_index_room(graf, vp, name_neighbour);
		free(name_neighbour);
		return (index_neighbour_room);
	}
	return (-1);
}

static int	search_edges(t_lem_in *lm, t_valid_pars *vp, char *name_room)
{
	int		i;
	int		len_room;
	int		index_neighbour_room;
	int		max_len;

	len_room = (int)ft_strlen(name_room);
	while (vp->map_edges->list != 0)
	{
		i = 0;
		if (vp->map_edges->list->str[0] == '#')
			return (-1);
		while (vp->map_edges->list->str[i] && vp->map_edges->list->str[i] !=
																			'-')
			i++;
		max_len = i > len_room ? i : len_room;
		if (ft_strncmp(vp->map_edges->list->str, name_room, max_len) == 0)
			return (search_index_room(&lm->graf, vp,
										vp->map_edges->list->str + ++i));
		else if ((index_neighbour_room = check_second_link(vp, &lm->graf,
														name_room, i)) >= 0)
			return (index_neighbour_room);
		vp->map_edges->list = vp->map_edges->list->next;
	}
	return (-1);
}

static void	init_list_edges_head(t_current_list_edges *list_edges,
											t_graf graf, int index_desired_room)
{
	t_list_edges_current_room	*new_list;

	new_list =
	(t_list_edges_current_room*)malloc(sizeof(t_list_edges_current_room));
	ft_bzero((void*)new_list, sizeof(t_list_edges_current_room));
	new_list->room = graf.rooms[index_desired_room];
	list_edges->head = new_list;
	list_edges->list = list_edges->head;
}

void		parsing_links(t_lem_in *lm, t_valid_pars *vp)
{
	t_list_edges_current_room	*new_list;
	int							i_desired_room;

	ft_bzero((void*)vp->list_edges, sizeof(t_current_list_edges));
	while (vp->map_edges->list != 0)
	{
		i_desired_room = search_edges(lm, vp,
								lm->graf.rooms[vp->index_current_room]->name);
		if (i_desired_room != -1)
		{
			if (vp->list_edges->head != 0)
			{
				new_list =
		(t_list_edges_current_room*)malloc(sizeof(t_list_edges_current_room));
				ft_bzero((void*)new_list, sizeof(t_list_edges_current_room));
				new_list->room = lm->graf.rooms[i_desired_room];
				vp->list_edges->list->next = new_list;
				vp->list_edges->list = vp->list_edges->list->next;
			}
			else
				init_list_edges_head(vp->list_edges, lm->graf, i_desired_room);
		}
		if (vp->map_edges->list != 0)
			vp->map_edges->list = vp->map_edges->list->next;
	}
}
