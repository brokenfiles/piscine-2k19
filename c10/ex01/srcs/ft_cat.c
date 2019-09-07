/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 12:04:44 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/22 01:39:11 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_cat.h"
#include <libgen.h>

void	write_stdin(void)
{
	char	buffer;
	int		r;

	while ((r = read(0, &buffer, 1)) != 0)
	{
		write(1, &buffer, 1);
	}
}

void	display_error(char *file_name, char *program_name)
{
	error(basename(program_name));
	error(": ");
	error(file_name);
	error(MSG_CANNOT_READ_FILE);
}

int		is_minus(char *argument)
{
	int	index;

	index = 0;
	while (argument[index])
	{
		if (argument[index] != '-')
			return (0);
		index++;
	}
	return (1);
}

void	ft_read(char *file_name, char **av, int index)
{
	char	buffer;
	int		fd;

	file_name = av[index];
	if ((fd = open(file_name, O_RDONLY)) == -1)
		display_error(file_name, av[0]);
	else
	{
		while (read(fd, &buffer, 1) == 1)
			write(1, &buffer, 1);
		close(fd);
	}
}

int		main(int ac, char **av)
{
	char	*file_name;
	int		index;

	index = 1;
	if (ac < 2)
		write_stdin();
	while (index < ac)
	{
		if (is_minus(av[index]))
		{
			write_stdin();
			index++;
			continue ;
		}
		file_name = av[index];
		ft_read(file_name, av, index);
		index++;
	}
}
