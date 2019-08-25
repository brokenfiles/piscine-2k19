/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 11:06:27 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/18 19:32:36 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_tail.h"
#include <libgen.h>
#include <stdlib.h>

#include <stdio.h>

void	ft_putstr_special(char *str, int n)
{
	write(1, str, n);
}

void	ft_strcpy(char *dest, char *src, int n)
{
	int	index;

	index = 0;
	while (index < n)
	{
		dest[index] = src[index];
		index++;
	}
}

void	read_stdin(int tail)
{
	char	*buffer;
	int		r;
	int		index;

	index = 0;
	buffer = malloc(sizeof(char) * (2 * tail));
	while ((r = read(0, &buffer[tail], tail)) > 0)
	{
		index += r;
		if (r < tail)
			break ;
		ft_strcpy(buffer, (buffer + tail), tail);
	}
	if (index < tail)
		ft_putstr_special((buffer + tail), index);
	else
		ft_putstr_special((buffer + r), tail);
}

int		contains_numbers(char **av)
{
	int	index;

	index = 0;
	while (av[1][index])
	{
		if (av[1][index] >= '0' && av[1][index] <= '9')
			return (1);
		index++;
	}
	return (0);
}

int		has_files_after(int ac, int size, char *pn, char **av)
{
	(void)pn;
	if (ac == 2 && size)
	{
		if (contains_numbers(av))
			read_stdin(size);
		else
		{
			ft_putstr(basename(pn));
			ft_putstr(": option requires an argument -- c\n");
			ft_putstr("usage: tail [-F | -f | -r] [-q]");
			ft_putstr(" [-b # | -c # | -n #] [file ...]\n");
		}
		return (0);
	}
	else if (ac == 3 && size)
	{
		if (!contains_numbers(av))
			read_stdin(size);
		else
			return (1);
		return (0);
	}
	else
		return (1);
}
