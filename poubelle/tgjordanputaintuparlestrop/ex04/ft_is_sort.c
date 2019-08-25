/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 16:49:52 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/14 10:26:50 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	index;
	int	result;
	int	sense;

	sense = 0;
	index = 0;
	while (index < length)
	{
		result = (*f)(tab[index], tab[index + 1]);
		if (sense == 0)
		{
			if (result == -1 || result == 1)
				sense = result;
			else
			{
				index++;
				continue;
			}
		}
		if (result == (-sense))
			return (0);
		index++;
	}
	return (1);
}
