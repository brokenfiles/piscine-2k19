/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_numeric.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 14:16:37 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/15 14:17:55 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_numeric(char *str)
{
	int	index;
	int	number;

	index = 0;
	number = 0;
	while (str[index])
	{
		if (str[index] >= '0' && str[index] <= '9')
			number++;
		index++;
	}
	return (number == index);
}
