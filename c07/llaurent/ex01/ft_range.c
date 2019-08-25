/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 16:33:17 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/08 15:06:49 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	len;
	int	index;

	index = 0;
	if (min >= max)
		return (NULL);
	len = max - min;
	if ((range = (int *)malloc(sizeof(*range) * (len))) == NULL)
		return (NULL);
	while (min < max)
	{
		range[index] = min;
		index++;
		min++;
	}
	return (range);
}
