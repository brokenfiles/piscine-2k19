/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 13:54:04 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/15 23:29:31 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_tail.h"
#include <stdio.h>

void	display_error(char *file_name, char *message, int dm, char *pn)
{
	error(pn);
	error(": ");
	if (!dm)
	{
		error(file_name);
		error(MSG_CANNOT_READ_FILE);
	}
	else
	{
		error(message);
		error(file_name);
	}
	error("\n");
}

int		f_size(char *file_name)
{
	int		index;
	char	buffer;
	int		fd;

	fd = open(file_name, O_RDONLY);
	index = 0;
	while (read(fd, &buffer, 1) != 0)
		index++;
	close(fd);
	return (index);
}

void	display_tail(int tail, int fd, char *file_name)
{
	int		index;
	char	buffer;
	int		file_size;

	index = 0;
	file_size = f_size(file_name);
	while (read(fd, &buffer, 1) != 0)
	{
		if (index >= file_size - tail)
			write(1, &buffer, 1);
		index++;
	}
}

void	display_file(int ac, char **av, int size)
{
	int		index;
	int		fd;
	char	*file_name;

	index = 3;
	while (index < ac)
	{
		file_name = av[index];
		if ((fd = open(file_name, O_RDONLY)) == -1)
			display_error(file_name, "", 0, av[0]);
		else
		{
			if (ac > 4)
				print_separator(file_name, index);
			display_tail(size, fd, file_name);
			close(fd);
		}
		index++;
	}
}

int		main(int ac, char **av)
{
	int		index;
	int		size;

	index = 3;
	size = 0;
	if (ac == 1)
		return (0);
	if (ac > 2)
	{
		if ((av[1][0] && av[1][1]) && av[1][0] == '-' && av[1][1] == 'c')
		{
			if (!ft_is_numeric(av[2]))
				display_error(av[2], MSG_ILLEGAL_OFFSET, 1, av[0]);
			size = ft_atoi(av[2]);
		}
	}
	display_file(ac, av, size);
}
