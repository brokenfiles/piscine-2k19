/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_separator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 14:55:41 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/15 14:58:00 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/ft_tail.h"

void	print_separator(char *file_name, int index)
{
	if (index > 3)
	{
		ft_putstr("\n");
	}
	ft_putstr("==> ");
	ft_putstr(file_name);
	ft_putstr(" <==\n");
}
