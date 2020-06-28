/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astamm <astamm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 23:16:23 by wmaykit           #+#    #+#             */
/*   Updated: 2019/12/17 01:12:15 by astamm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int			get_index_options(char *options_in)
{
	char		**options;
	int			index_options;

	options = (char *[]){OPTIONS};
	index_options = 0;
	if (*options_in++ != '-')
		return (-1);
	while (*options[index_options])
	{
		if (options[index_options][0] == options_in[0])
		{
			if (options_in[1] &&
					ft_strcmp(options[index_options], options_in))
				return (-1);
			return (index_options);
		}
		++index_options;
	}
	return (-1);
}

static unsigned int	get_all_in_str(char *str)
{
	char			**options;
	int				index_options;
	unsigned int	o_options;

	++str;
	options = (char *[]){OPTIONS};
	o_options = 0;
	while (*str)
	{
		index_options = 0;
		while (*options[index_options] && options[index_options][0] != *str)
			++index_options;
		if (!*options[index_options])
			return (O_ERROR);
		else
			o_options |= (1 << index_options);
		++str;
	}
	return (o_options);
}

unsigned int		get_options(int ac, char **av)
{
	unsigned int	o_options;
	int				index_av;
	int				index_options;

	index_av = 1;
	o_options = 0;
	while (index_av < ac)
	{
		if ((index_options = get_index_options(av[index_av])) > -1)
			o_options |= (1 << index_options);
		else if (av[index_av][0] != '-' || !av[index_av][1] ||
				(o_options |= get_all_in_str(av[index_av])) & O_ERROR)
		{
			ft_putendl_fd("ERROR\nInvalid options", 2);
			exit(EXIT_FAILURE);
		}
		++index_av;
	}
	return (o_options);
}
