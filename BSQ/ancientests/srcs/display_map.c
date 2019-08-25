/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 13:39:10 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/19 14:18:19 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int	display_map(t_map map)
{
	int	index;

	index = 0;
	while (map.tab[index])
	{
		ft_putstr(map.tab[index]);
		write(STANDARD_OUTPUT, "\n", 1);
		index++;
	}
	return (SUCCESS);
}
