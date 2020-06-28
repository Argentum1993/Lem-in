/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_links.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 14:15:05 by astamm            #+#    #+#             */
/*   Updated: 2019/12/16 15:20:24 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		parsing_check_valid_links(t_lem_in *lm, t_valid_pars *vp)
{
	int		i;
	char	*first_room;

	vp->map_edges->list = vp->map_edges->head;
	while (vp->map_edges->list != 0)
	{
		i = 0;
		if (vp->map_edges->list->str[i] == '#')
			return ;
		while (vp->map_edges->list->str[i] != '-')
			i++;
		first_room = ft_strsub(vp->map_edges->list->str, 0, i);
		if (search_index_room(&lm->graf, vp, first_room) == -1)
			error_invalid_links(&lm->graf, vp, &first_room);
		if (search_index_room(&lm->graf, vp, vp->map_edges->list->str + ++i)
																		== -1)
			error_invalid_links(&lm->graf, vp, &first_room);
		ft_strdel(&first_room);
		if (vp->map_edges->list != NULL)
			vp->map_edges->list = vp->map_edges->list->next;
	}
	vp->map_edges->list = vp->map_edges->head;
}
