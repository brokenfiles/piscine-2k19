/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 18:39:08 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/17 19:38:01 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *base_to)
{
	int i;

	i = 0;
	while (base_to[i] != '\0')
	{
		i++;
	}
	return (i);
}

int		ft_base_len(long nbr, char *base_to)
{
	long	i;
	int		baselen;
	int		returned_int;

	baselen = ft_strlen(base_to);
	i = 1;
	returned_int = 1;
	while (baselen * i <= nbr)
	{
		returned_int++;
		i = i * baselen;
	}
	return (returned_int);
}

char	*calc(char *str, char *base_to, long nbr, int negative)
{
	int	i;

	if (negative == 1)
		i = ft_base_len(nbr, base_to);
	else
		i = ft_base_len(nbr, base_to) - 1;
	while (i >= negative)
	{
		str[i] = base_to[(nbr % ft_strlen(base_to))];
		nbr = nbr / ft_strlen(base_to);
		i--;
	}
	return (str);
}

char	*ft_putnbr_base(int nb, char *base_to)
{
	char	*str;
	long	nbr;
	int		negative;

	nbr = (long)nb;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		if (!(str = malloc((ft_base_len(nbr, base_to) + 2) * sizeof(*str))))
			return (0);
		str[0] = '-';
		str[ft_base_len(nbr, base_to) + 1] = '\0';
		negative = 1;
	}
	else
	{
		if (!(str = malloc((ft_base_len(nbr, base_to) + 1) * sizeof(*str))))
			return (0);
		str[ft_base_len(nbr, base_to)] = '\0';
		negative = 0;
	}
	return (calc(str, base_to, nbr, negative));
}
