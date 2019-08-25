/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:02:49 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/08 15:10:19 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
