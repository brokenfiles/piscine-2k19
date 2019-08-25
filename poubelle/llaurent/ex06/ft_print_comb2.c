/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 10:59:30 by llaurent          #+#    #+#             */
/*   Updated: 2019/07/31 11:56:27 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put_char(char c);

void	ft_print_comb2(void);

void	display(int	nb);

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 99)
	{
		b = a + 1;
		while (b <= 99)
		{
			display(a);
			ft_put_char(' ');
			display(b);
			if (a < 98 || b < 99)
			{
				write(1, ", ", 2);
			}
			b++;
		}
		a++;
	}
}

void	ft_put_char(char c)
{
	write(1, &c, 1);
}

void	display(int nb)
{
	int a;
	int b;

	a = nb / 10;
	b = nb % 10;
	ft_put_char(a + 48);
	ft_put_char(b + 48);
}
