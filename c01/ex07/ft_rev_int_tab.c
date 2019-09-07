/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 08:39:41 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/11 21:51:59 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int i;
	int j;
	int val_tab;
	int tab2[size];

	i = size - 1;
	j = 0;
	while (i >= 0)
	{
		val_tab = tab[i];
		tab2[j] = val_tab;
		j++;
		i--;
	}
	i = 0;
	while (i < size)
	{
		tab[i] = tab2[i];
		i++;
	}
}
