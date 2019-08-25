/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 09:54:01 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/05 10:25:50 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0 && nb > 0)
		return (1);
	return (nb * ft_iterative_power(nb, power - 1));
}

int	main(void)
{
	printf("%d\n", ft_iterative_power(2, 4));
}
