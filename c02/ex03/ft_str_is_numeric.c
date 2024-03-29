/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 15:28:29 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/01 15:36:12 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	result;
	int	i;
	int	c;

	result = 0;
	i = 0;
	while (str[i])
	{
		c = str[i];
		if ((c >= 48 && c <= 57))
		{
			result++;
		}
		i++;
	}
	return (i == result);
}
