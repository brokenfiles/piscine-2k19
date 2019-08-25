/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 11:12:13 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/05 16:49:45 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	is_an_integer(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (str[index] == '.')
			return (0);
	}
	return (1);
}

int	ft_sqrt(int nb)
{
	float	temp;
	float	sqrt;

	sqrt = nb / 2;
	temp = 0;
	while (sqrt != temp)
	{
		temp = sqrt;
		sqrt = (nb / temp + temp) / 2;
	}
	if ((int) sqrt - sqrt != 0)
		return (0);
	return ((int)sqrt);
}

int	main(int argc, char **argv)
{
	printf("%d\n", ft_sqrt(atoi((char *)argv[1])));
}
