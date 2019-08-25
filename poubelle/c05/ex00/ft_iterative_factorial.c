/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 17:52:42 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/04 18:04:10 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_iterative_factorial(int nb)
{
	int	index;
	int	result;
	int	fact;

	index = 0;
	result = 1;
	if (!nb)
		return (1);
	while(index < nb)
	{
		result *= (index + 1);
		index++;
	}
	return (result);
}

int main(int argc, char **argv)
{
	printf("%d\n", ft_iterative_factorial(atoi(argv[1])));
	return 0;
}
