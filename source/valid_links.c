/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 00:44:07 by astamm            #+#    #+#             */
/*   Updated: 2019/12/16 03:09:47 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	valid_links(t_valid_pars *vp)
{
	int null;

	null = 0;
	valid_name_room(vp->str, &vp->i);
	if (vp->str[vp->i] == '-')
	{
		vp->i++;
		valid_name_room(vp->str + vp->i, &null);
		if (vp->map_edges->head != 0)
			valid_save_map_edges(vp);
		else
			valid_inicial_map_edges(vp);
	}
	else
		print_error_and_free_mem(vp, "Invalid name room in list links");
}

void		valid_str_link(t_valid_pars *vp)
{
	vp->links_processing = True;
	vp->i = 0;
	if (vp->str[0] == 'L')
		error_processing("Invalid name room L");
	if (vp->str[0] == '#' && vp->str[1] != '#')
		valid_save_comment(vp);
	else if (vp->str[0] != 'L')
		valid_links(vp);
	else
		print_error_and_free_mem(vp, "Invalid line in list links");
}
