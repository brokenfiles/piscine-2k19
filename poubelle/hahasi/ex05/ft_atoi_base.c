/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 15:20:39 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/15 18:58:54 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check_base(char *base)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		z = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if ((base[i] >= 0 && base[i] <= 32) || (base[i] >= 42 && base[i] <= 47)
				|| (base[i] == 37 || base[i] == 127))
			return (0);
		while (base[z])
		{
			if (base[i] == base[z])
				return (0);
			z++;
		}
		i++;
	}
	return (1);
}

int		change_sign(char *str, int *sign, int i)
{
	int	index2;

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

int		check_in_base(char c, char *base, int function)
{
	int	index;

	index = 0;
	if (!function)
	{
		while (base[index])
		{
			if (base[index] == c)
				return (1);
			index++;
		}
		return (0);
	}
	else
	{
		while (base[index])
		{
			if (base[index] == c)
				break ;
			index++;
		}
		return (index);
	}
	return (-1);
}

int		base_len(char *base)
{
	int	index;

	index = 0;
	while (base[index])
	{
		index++;
	}
	return (index);
}

int		ft_atoi_base(char *str, char *base)
{
	int	result;
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	result = 0;
	if (!check_base(base))
		return (0);
	while ((str[i] >= 8 && str[i] <= 13) || str[i] == ' ')
		i++;
	i = change_sign((char *)str, &sign, i);
	while (str[i])
	{
		if (check_in_base(str[i], base, 0))
		{
			result = result * base_len(base);
			result += check_in_base(str[i], base, 1);
		}
		else
			return (0);
		i++;
	}
	return (result * sign);
}
