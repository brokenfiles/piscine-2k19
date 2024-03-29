/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 11:12:13 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/06 12:39:26 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int i;

	i = 46340;
	if (nb > 0)
	{
		while ((i * i) > nb)
		{
			i--;
		}
		if ((i * i) == nb)
			return (i);
	}
	return (0);
}
