/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 15:50:16 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/01 15:55:10 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	result;
	int	i;
	int	c;

	result = 0;
	i = 0;
	while (str[i])
	{
		c = str[i];
		if (c >= 65 && c <= 90)
		{
			result++;
		}
		i++;
	}
	return (i == result);
}
