/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 11:06:27 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/18 14:46:33 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_tail.h"
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putstr_special(char *str, int n)
{
	int	index;

	index = 0;
	while (index < n)
	{
		write(1, &str[index], 1);
		index++;
	}
}

void	ft_strcpy(char *dest, char *src)
{
	int	index;

	index = 0;
	while (src[index])
	{
		dest[index] = src[index];
		index++;
	}
}

void	read_stdin(int tail)
{
	int		index;
	char	*buffer;
	int		r;

	buffer = malloc(sizeof(char) * (2 * tail));
	index = 0;
	while ((r = read(0, &buffer[tail], tail)) != 0)
	{
		if (r < tail)
			break ;
		ft_strcpy(buffer, (buffer + tail));
		index++;
	}
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
