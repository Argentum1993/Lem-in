/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_valid_in_parsing.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 02:01:26 by astamm            #+#    #+#             */
/*   Updated: 2019/12/16 15:19:37 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	error_invalid_links(t_graf *graf, t_valid_pars *vp, char **str)
{
	ft_strdel((char**)str);
	free_map_rooms(vp);
	free_map_edges(vp);
	ft_memdel((void**)&vp->list_edges);
	destroy_graf(graf);
	error_processing("Invalid Links");
}

void	error_repeat_commands(t_valid_pars *vp)
{
	free_map_rooms(vp);
	free_map_edges(vp);
	ft_memdel((void**)&vp->list_edges);
	error_processing("Incorrect using command");
}
