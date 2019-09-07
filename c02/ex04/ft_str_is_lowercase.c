/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 15:38:27 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/01 15:49:35 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	result;
	int	i;
	int	c;

	result = 0;
	i = 0;
	while (str[i])
	{
		c = str[i];
		if (c >= 97 && c <= 122)
		{
			result++;
		}
		i++;
	}
	return (i == result);
}
