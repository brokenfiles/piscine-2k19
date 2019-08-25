/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 09:51:43 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/20 17:48:27 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	tohex(unsigned char *str, int i)
{
	char	g;
	char	d;
	char	*base_hexa;

	base_hexa = "0123456789abcdef";
	g = base_hexa[(str[i] / 16)];
	d = base_hexa[(str[i] % 16)];
	ft_putchar(92);
	ft_putchar(g);
	ft_putchar(d);
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	*src;

	i = 0;
	src = (unsigned char *)str;
	while (src[i] != '\0')
	{
		if (src[i] < ' ' || src[i] > 126)
		{
			tohex(src, i);
		}
		else
		{
			ft_putchar(src[i]);
		}
		i++;
	}
}
