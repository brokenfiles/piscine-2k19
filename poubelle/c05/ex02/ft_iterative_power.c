/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 10:13:06 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/05 10:22:14 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	first;

	first = nb;
	if (power < 0)
		return (0);
	if (power == 0 && nb > 0)
		return (1);
	while (power > 1)
	{
		nb *= first;
		power--;
	}
	return (nb);
}

int	main(void)
{
	printf("%d\n", ft_iterative_power(4534545, 0));
}
