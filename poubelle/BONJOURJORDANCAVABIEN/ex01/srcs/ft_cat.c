/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 12:04:44 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/15 22:56:32 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_cat.h"

void	write_stdin(void)
{
	char	buffer[BUFF_SIZE + 1];
	int		r;

	while ((r = read(0, buffer, BUFF_SIZE)) != 0)
	{
		buffer[r] = '\0';
		ft_putstr(buffer);
	}
}

void	display_error(char *file_name, char *program_name)
{
	error(program_name);
	error(": ");
	error(file_name);
	error(MSG_CANNOT_READ_FILE);
}

int		main(int ac, char **av)
{
	int		fd;
	char	buffer;
	char	*file_name;
	int		index;

	index = 1;
	if (ac < 2)
		write_stdin();
	while (index < ac)
	{
		file_name = av[index];
		if ((fd = open(file_name, O_RDONLY)) == -1)
			display_error(file_name, av[0]);
		else
		{
			while (read(fd, &buffer, 1) != 0)
				write(1, &buffer, 1);
			close(fd);
		}
		index++;
	}
}
