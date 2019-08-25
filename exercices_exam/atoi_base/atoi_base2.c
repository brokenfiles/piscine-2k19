/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 17:46:25 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/22 18:00:27 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	pos_in_base(char c, int size_base)
{
	char	*base;
	char	*base1;
	int		index;

	index = 0;
	base = "0123456789ABCDEF";
	base1 = "0123456789abcdef";
	while (index < size_base)
	{
		if (base[index] == c || base1[index] == c)
			return (index);
		index++;
	}
	return (0);
}

int	is_a_base_char(int c)
{
	return ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	ft_atoi_base(char *str, int size_base)
{
	int	result;
	int	sign;
	int	index;

	result = 0;
	sign = 1;
	index = 0;
	write(1, "r\n", 2);
	while ((str[index] >= 8 && str[index] <= 13) || str[index] == ' ')
		index++;
	if (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			sign = -1;
		index++;
	}
	write(1, "r\n", 2);
	while (is_a_base_char(str[index]))
	{
		result = (result * size_base) + pos_in_base(str[index], size_base);
		index++;
	}
	return (result * sign);
}

int	main(int ac, char **av)
{
	printf("atoi_base result : %d\n", ft_atoi_base(av[1], atoi(av[2])));
}
