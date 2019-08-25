/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 11:57:11 by llaurent          #+#    #+#             */
/*   Updated: 2019/07/31 13:07:59 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put_char(char c);

void	ft_putnbr(int nbr)
{
	int	nbr1;
	int	nbr2;

	if (nbr < 10)
	{
		ft_put_char(nbr + 48);
	}
	else if (nbr > 10)
	{
		nbr1 = nbr / 10;
		nbr2 = nbr % 10;
		ft_put_char(nbr1 + 48);
		ft_put_char(nbr2 + 48);
	}
}

void	ft_put_char(char c)
{
	write(1, &c, 1);
}
