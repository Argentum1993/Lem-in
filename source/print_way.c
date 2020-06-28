/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interation2_print_way.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <wmaykit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 17:17:49 by wmaykit           #+#    #+#             */
/*   Updated: 2019/12/14 20:15:33 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		print_way(t_way *way)
{
	int		index;
	int		num;

	num = 1;
	index = 0;
	while (index < way->amount_room)
	{
		ft_printf("%d) %s\n", num++, way->arr_rooms[index]->name);
		++index;
	}
	ft_printf("\n");
}
