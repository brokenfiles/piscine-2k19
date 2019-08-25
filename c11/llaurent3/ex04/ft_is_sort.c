/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 16:49:52 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/14 15:04:51 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	compare(int a, int b)
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
	while (index < length - 1)
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
