/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 16:52:01 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/06 09:19:50 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	float	index;
	int		divisers;
	float	diviser;

	index = 1;
	diviser = 0.0;
	divisers = 0;
	while (index <= nb)
	{
		diviser = (float)(nb / index);
		if ((int)diviser - diviser == 0)
		{
			divisers++;
		}
		index++;
	}
	return (divisers == 2);
}
