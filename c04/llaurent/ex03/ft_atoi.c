/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 16:27:04 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/04 17:23:23 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	change_sign(const char *str, int *sign, int i)
{
	int index2;

	index2 = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign = -*(sign);
		index2 = 0;
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 8 && str[i] <= 13) || str[i] == ' ')
		i++;
	i = change_sign((const char *)str, &sign, i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

int main(int argc, const char *argv[])
{
	printf("%d\n", ft_atoi((char *)argv[1]));
	return 0;
}
