/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 18:55:56 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/19 18:58:41 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	t_list	current;
	int		index;

	index = 0;
	current = *begin_list;
	while (current.next != 0)
	{
		current = *current.next;
		index++;
	}
	return (index);
}
