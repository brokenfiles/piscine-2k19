/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 11:52:13 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/18 18:16:49 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/ft_tail.h"
#include <libgen.h>

void	error(char *error)
{
	int	index;

	index = 0;
	while (error[index])
	{
		write(2, &error[index], 1);
		index++;
	}
}

int		verif(int *size, int *index2, char **av, int ac)
{
	if ((av[1][0] && av[1][1]) && av[1][0] == '-' && av[1][1] == 'c')
	{
		while (av[1][*index2])
			*index2 = *index2 + 1;
		if (*index2 - 2 > 0)
			*size = ft_atoi(av[1]);
		if ((ac > 2 && !ft_is_numeric(av[2]) && (!*size || *size == -1)))
		{
			display_error(av[2], MSG_ILLEGAL_OFFSET, 1, av[0]);
			return (0);
		}
		if (ac == 2 && (!*size || *size == -1))
		{
			ft_putstr(basename(av[0]));
			ft_putstr(": option requires an argument -- c\n");
			ft_putstr("usage: tail [-F | -f | -r] [-q]");
			ft_putstr(" [-b # | -c # | -n #] [file ...]\n");
			return (0);
		}
		if (*size == -1 && ac > 2)
			*size = ft_atoi(av[2]);
	}
	return (1);
}
