/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 11:57:11 by llaurent          #+#    #+#             */
/*   Updated: 2019/07/31 18:01:01 by llaurent         ###   ########.fr       */
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

	if (nb < 0)
	{
		ft_put_char('-');
		ft_putnbr(nb * -1);
	}
	else if (nb < 10 && nb > 0)
	{
		ft_put_char(nb + 48);
	}
	else if (nb > 10)
	{
		new_nbr = nb % 10;
		ft_putnbr(nb / 10);
		ft_put_char(new_nbr + 48);
	}
	else
	{
		ft_put_char(nb + 48);
	}
}
