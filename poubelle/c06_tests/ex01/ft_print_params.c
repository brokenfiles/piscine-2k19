/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 19:11:36 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/04 19:35:31 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int		index;
	char	c;

	index = 0;
	while (str[index])
	{
		c = str[index];
		write(1, &c, 1);
		index++;
	}
}

int	main(int argc, char **argv)
{
	int	index;

	index = 1;
	while (index < argc)
	{
		ft_putstr(argv[index]);
		ft_putstr("\n");
		index++;
	}
	return (0);
}
