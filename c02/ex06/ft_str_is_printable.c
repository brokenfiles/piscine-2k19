/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 15:56:41 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/01 16:12:18 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	result;
	int	i;
	int	c;

	result = 0;
	i = 0;
	while (str[i])
	{
		c = str[i];
		if (c >= 32 && c <= 126)
		{
			result++;
		}
		i++;
	}
	return (i == result);
}
