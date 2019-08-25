/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 12:04:44 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/15 16:40:06 by llaurent         ###   ########.fr       */
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

void	display_error(char *file_name)
{
	error("ft_cat: ");
	error(file_name);
	error(MSG_CANNOT_READ_FILE);
}

int		main(int ac, char **av)
{
	int		fd;
	char	buffer[BUFF_SIZE + 1];
	int		r;
	char	*file_name;
	int		index;

	index = 1;
	if (ac < 2)
		write_stdin();
	while (index < ac)
	{
		file_name = av[index];
		if ((fd = open(file_name, O_RDONLY)) == -1)
			display_error(file_name);
		else
		{
			r = read(fd, buffer, BUFF_SIZE);
			buffer[r] = '\0';
			ft_putstr(buffer);
			close(fd);
		}
		index++;
	}
}