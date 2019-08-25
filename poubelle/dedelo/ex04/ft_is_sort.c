/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 16:49:52 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/13 19:31:00 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	index;

	index = 0;
	while (index < length - 1)
	{
		if ((*f)(tab[index], tab[index + 1]) > 0)
			return (0);
		index++;
	}
	return (1);
}
