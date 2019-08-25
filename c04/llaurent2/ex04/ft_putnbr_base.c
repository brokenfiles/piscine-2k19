/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 21:03:23 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/15 19:11:05 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		check_base_dupes(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i] != '\0')
	{
		while (base[j] != '\0')
		{
			if (base[i] == base[j] && i != j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		check_base_chars(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] <= '/' || (base[i] >= ':' && base[i] <= '@') ||
				(base[i] >= '[' && base[i] < 'a') || base[i] >= '{')
			return (1);
		i++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int	div;
	long int	base_size;

	div = 0;
	base_size = ft_strlen(base);
	if (check_base_chars(base) || check_base_dupes(base) ||
			ft_strlen(base) <= 1)
		return ;
	div = nbr;
	if (div < 0)
	{
		ft_putchar('-');
		div *= -1;
	}
	if (div >= base_size)
		ft_putnbr_base(div / base_size, base);
	ft_putchar(base[div % base_size]);
}
