/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 17:23:25 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/22 18:22:02 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int		ft_base(char c, int size_base)
{
	int		i;
	char	*base_l = "0123456789abcdef";
	char	*base_u = "0123456789ABCDEF";

	i = 0;
	while (i < size_base)
	{
		if (c == base_l[i] || c == base_u[i])
			return (i);
		i++;
	}
	return (0);
}

int		ft_atoi_base(char *str, int size_base)
{
	int	i;
	int	signe;
	int	res;

	i = 0;
	signe = 1;
	res = 0;
	while (ft_space(str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
	{
		res = (res * size_base) + ft_base(str[i], size_base);
		i++;
	}
	return (signe * res);
}

int	main(int ac, char **av)
{
	printf("Atoi result : %d\n", ft_atoi_base(av[1], atoi(av[2])));
}
