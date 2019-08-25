/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 17:39:58 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/05 17:53:04 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_is_prime(int nb)
{
	float	index;
	int		divisers;
	float	diviser;

	index = 1;
	diviser = 0.0;
	divisers = 0;
	while (index <= nb)
	{
		diviser = (float)(nb / index);
		if ((int) diviser - diviser == 0)
		{
			divisers++;
		}
		index++;
	}
	return (divisers == 2);
}

int	ft_find_next_prime(int nbr)
{
	int	index;

	index = nbr + 1;
	while (!ft_is_prime(index))
	{
		index++;
	}
	return (index);
}

int main(int argc, char **argv)
{
	int prime = ft_find_next_prime(atoi((char *)argv[1]));
	printf("prime found :%d\n", prime);
	printf("is prime : %d\n", ft_is_prime(prime));
	return (0);
}
