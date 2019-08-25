/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_text.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 12:10:19 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/19 12:11:30 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	ft_display_text(int output, char *message)
{
	int	index;

	index = 0;
	while (message[index])
	{
		write(output, &message[index], 1);
		index++;
	}
}
