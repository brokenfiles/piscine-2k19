/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 19:41:03 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/04 20:24:58 by llaurent         ###   ########.fr       */
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
	argc--;
	while (argc > 0)
	{
		ft_putstr(argv[argc]);
		ft_putstr("\n");
		argc--;
	}
	return (0);
}
