/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:02:49 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/11 23:45:09 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_putnbr(int nb);

int	ft_ultimate_range(int **range, int min, int max)
{
	int	len;
	int	*cp_range;
	int	index;

	index = 0;
	if (min >= max)
		return (0);
	len = max - min;
	if ((cp_range = (int *)malloc(sizeof(*cp_range) * (len))) == NULL)
		return (0);
	while (min < max)
	{
		cp_range[index] = min;
		index++;
		min++;
	}
	*range = cp_range;
	return (index);
}

int	main(void)
{
	int	*tab;
	int	index;

	index = 10;
	ft_ultimate_range(&tab, 10, 20);
	while (index < 20)
	{
		 
		index++;
	}
	free(tab);
}
