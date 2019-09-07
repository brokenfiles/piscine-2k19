/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 17:39:58 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/06 12:55:53 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int i;

	if ((nb % 2 == 0 && nb != 2) || nb <= 1)
		return (0);
	i = 3;
	while (i * i <= nb && i < 46349)
	{
		if ((nb % i) == 0)
			return (0);
		i = i + 2;
	}
	return (1);
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
