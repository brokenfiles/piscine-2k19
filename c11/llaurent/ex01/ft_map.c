/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 10:38:51 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/14 09:37:16 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	index;
	int	*returned_table;

	if (!(returned_table = (int *)malloc(sizeof(int) * length)))
		return (0);
	index = 0;
	while (index < length)
	{
		returned_table[index] = (*f)(tab[index]);
		index++;
	}
	return (returned_table);
}
