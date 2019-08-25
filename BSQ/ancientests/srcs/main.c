/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 10:33:30 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/20 15:38:28 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"
#include <stdio.h>

void	err(int *index, int ac, char *err_msg)
{
	ft_putstr(err_msg);
	if (*index != ac - 1)
		ft_putstr("\n");
	*index += 1;
}

void	write_stdin(void)
{
	char	buffer[1000];
	int		r;

	while ((r = read(0, buffer, 1000)) != 0)
	{

	}
	buffer[r] = 0;
	ft_putstr(buffer);
}

int	main(int ac, char **av)
{
	t_map	map;
	int		index;

	index = 1;
	if (ac < 2)
		write_stdin();
	while (index < ac)
	{
		if (get_map(1, -1, av[index], &map) != SUCCESS)
		{
			err(&index, ac, MSG_ERR_CANNOT_READ_MAP);
			continue;
		}
		if (!contains_only(map.tab, map.data.c_void, map.data.c_obs))
		{
			err(&index, ac, MSG_ERR_CANNOT_READ_MAP);
			continue;
		}
		fill_map(&map);
		display_map(map);
		if (ac > 2 && index != ac - 1)
			ft_putstr("\n");
		index++;
	}
	return (SUCCESS);
}
