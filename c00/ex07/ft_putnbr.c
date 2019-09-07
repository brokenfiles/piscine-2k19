/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 11:57:11 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/09 09:46:30 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put_char(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int	new_nbr;

	if (nb == -2147483648)
	{
		ft_putnbr(-214748);
		ft_putnbr(3648);
		return ;
	}
	if (nb < 0)
	{
		ft_put_char('-');
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ft_put_char(nb + '0');
	}
}
