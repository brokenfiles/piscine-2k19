/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 16:49:52 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/14 13:48:02 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	compare(int	 a, int b)
{
	if (a < b)
		return (-1);
	else if (a == b)
		return (0);
	else
		return (1);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	index;
	int	result;
	int	way;

	way = 0;
	index = 0;
	while (index < length)
	{
		result = (*f)(tab[index], tab[index + 1]);
		if (way == 0)
		{
			if (result == -1 || result == 1)
				way = result;
			else
			{
				index++;
				continue;
			}
		}
		if (result == (-way))
			return (0);
		index++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int*tab;
	int	index;

	index = 0;
	av++;
	tab = malloc(sizeof(int) * ac);
	while (index < ac - 1)
	{
		tab[index] = atoi(av[index]);
		index++;
	}
	printf("%d\n", ft_is_sort(tab, ac - 1, &compare));
}
