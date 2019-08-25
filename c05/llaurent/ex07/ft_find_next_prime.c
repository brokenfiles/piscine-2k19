/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 17:39:58 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/06 09:39:59 by llaurent         ###   ########.fr       */
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

int	ft_find_next_prime(int nb)
{
	int	index;

	index = nb + 1;
	if (ft_is_prime(nb))
		return (nb);
	while (!ft_is_prime(index))
	{
		index++;
	}
	return (index);
}
