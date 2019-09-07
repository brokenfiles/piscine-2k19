/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_separator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 14:55:41 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/18 15:15:30 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/ft_tail.h"

void	print_separator(char *file_name, int index, int start, int last_error)
{
	if (index > (start > 0 ? 2 : 3) && !last_error)
	{
		ft_putstr("\n");
	}
	ft_putstr("==> ");
	ft_putstr(file_name);
	ft_putstr(" <==\n");
}
