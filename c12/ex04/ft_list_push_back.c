/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 21:04:47 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/19 21:46:38 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new_element;

	new_element = *begin_list;
	if (!new_element)
		new_element = ft_create_element(data);
	else
	{
		while (new_element->next)
			new_element = new_element->next;
		list->next = ft_create_element(data);
	}
}
