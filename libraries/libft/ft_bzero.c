/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 09:27:42 by mwuckert          #+#    #+#             */
/*   Updated: 2019/12/17 16:00:46 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

static void	ft_bzero_by_words(void *mem, size_t words)
{
	unsigned long	*mem_64;
	unsigned long	*end;

	end = (unsigned long *)mem + words;
	mem_64 = (unsigned long *)mem;
	while (mem_64 < end)
		*mem_64++ = 0;
}

static void	ft_bzero_by_byte(void *mem, size_t byte)
{
	unsigned char	*mem_8;
	unsigned char	*end;

	mem_8 = (unsigned char *)mem;
	end = (unsigned char *)mem + byte;
	while (mem_8 < end)
		*mem_8++ = 0;
}

void		ft_bzero(void *s, size_t n)
{
	size_t			words;

	if ((words = n / 8))
	{
		ft_bzero_by_words(s, words);
		s = (unsigned char *)s + words * 8;
	}
	ft_bzero_by_byte(s, n % 8);
}
