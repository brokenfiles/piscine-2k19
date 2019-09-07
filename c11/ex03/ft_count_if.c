/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 15:41:38 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/13 19:03:50 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (index < length)
	{
		if ((*f)(tab[index]) != 0)
			count++;
		index++;
	}
	return (count);
}
