/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 13:54:04 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/15 15:52:14 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_tail.h"

void	write_stdin(void)
{
	char	buffer[BUFF_SIZE + 1];
	int		r;

	while (1)
	{
		if ((r = read(0, buffer, BUFF_SIZE)) != -1)
		{
			buffer[r] = '\0';
			ft_putstr(buffer);
		}
	}
}

void	display_error(char *file_name, char *message, int display_message)
{
	error("ft_tail: ");
	if (!display_message)
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

void	display_tail(int tail, char buffer[BUFF_SIZE + 1], int r)
{
	int	index;

	index = r - tail;
	index = (index < 0 ? 0 : index);
	while (buffer[index])
	{
		write(1, &buffer[index], 1);
		index++;
	}
}

void	display_file(int ac, char **av, int size)
{
	int		index;
	char	buffer[BUFF_SIZE + 1];
	int		fd;
	int		r;
	char	*file_name;

	index = 3;
	while (index < ac)
	{
		file_name = av[index];
		if ((fd = open(file_name, O_RDONLY)) == -1)
			display_error(file_name, "", 0);
		else
		{
			if (ac > 4)
				print_separator(file_name, index);
			r = read(fd, buffer, BUFF_SIZE);
			buffer[r] = '\0';
			display_tail(size, buffer, r);
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
		write_stdin();
	if (ac > 2)
	{
		if ((av[1][0] && av[1][1]) && av[1][0] == '-' && av[1][1] == 'c')
		{
			if (!ft_is_numeric(av[2]))
				display_error(av[2], MSG_ILLEGAL_OFFSET, 1);
			size = ft_atoi(av[2]);
		}
	}
	display_file(ac, av, size);
}
