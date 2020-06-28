/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 01:13:00 by astamm            #+#    #+#             */
/*   Updated: 2019/12/17 15:24:10 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	error_processing(char *str)
{
	write(2, "ERROR\n", 6);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

void	print_error_and_free_mem(t_valid_pars *vp, char *str)
{
	ft_memdel((void**)&vp->str);
	free_map_rooms(vp);
	free_map_edges(vp);
	error_processing(str);
}
