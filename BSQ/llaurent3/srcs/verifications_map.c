/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifications_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 15:10:50 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/21 19:33:30 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int	contains_only(char **tab, char c_1, char c_2)
{
	int	index;
	int	index2;

	index = 0;
	index2 = 0;
	if (!tab || !*tab)
		return (0);
	while (tab[index])
	{
		index2 = 0;
		while (tab[index][index2])
		{
			if (tab[index][index2] != c_1 && tab[index][index2] != c_2)
				return (0);
			index2++;
		}
		index++;
	}
	return (1);
}
