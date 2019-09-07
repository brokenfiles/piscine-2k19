/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 11:52:13 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/15 22:42:13 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	error(char *error)
{
	int	index;

	index = 0;
	while (error[index])
	{
		write(2, &error[index], 1);
		index++;
	}
}
