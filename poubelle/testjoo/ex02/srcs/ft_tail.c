/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 13:54:04 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/18 16:52:20 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_tail.h"
#include <libgen.h>

int		display_error(char *file_name, char *message, int dm, char *pn)
{
	error(basename(pn));
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
	return (1);
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

int		display_tail(int tail, int fd, char *file_name, int *last_error)
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
	close(fd);
	*last_error = 0;
	return (1);
}

void	display_file(int ac, char **av, int size, int start)
{
	int		index;
	int		fd;
	char	*file_name;
	int		last_error;
	int		has_ar_success;

	has_ar_success = 0;
	last_error = 0;
	index = (start > 0 ? 2 : 3);
	while (index < ac)
	{
		file_name = av[index];
		if ((fd = open(file_name, O_RDONLY)) == -1)
			last_error = display_error(file_name, "", 0, av[0]);
		else
		{
			if (index > (start > 0 ? 2 : 3) && last_error && has_ar_success)
				write(1, "\n", 1);
			if (ac > (start > 0 ? 3 : 4))
				print_separator(file_name, index, start, last_error);
			has_ar_success = display_tail(size, fd, file_name, &last_error);
		}
		index++;
	}
}

int		main(int ac, char **av)
{
	int		size;
	int		index2;

	size = -1;
	index2 = 2;
	if (ac == 1)
		return (0);
	if (ac >= 2)
	{
		if (!verif(&size, &index2, av, ac))
			return (0);
		if (!has_files_after(ac, size, av[0], av))
			return (0);
	}
	display_file(ac, av, size, index2 - 2);
}
