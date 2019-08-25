/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 15:36:00 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/15 22:48:42 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_display_file.h"

int		main(int ac, char **av)
{
	int		fd;
	char	buffer;
	char	*file_name;

	if (ac < 2)
	{
		error(MSG_FILE_NAME_MISSING);
		return (ERR_FILE_NAME_MISSING);
	}
	if (ac > 2)
	{
		error(MSG_TOO_MANY_ARGUMENTS);
		return (ERR_TOO_MANY_ARGUMENTS);
	}
	file_name = av[1];
	if ((fd = open(file_name, O_RDONLY)) == -1)
	{
		error(MSG_CANNOT_READ_FILE);
		return (ERR_CANNOT_READ_FILE);
	}
	while (read(fd, &buffer, 1) != 0)
		write(1, &buffer, 1);
	close(fd);
}
