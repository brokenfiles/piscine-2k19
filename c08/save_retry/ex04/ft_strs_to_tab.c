/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 11:56:52 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/07 18:48:47 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

char				*ft_strcpy(char *src, int size)
{
	int		index;
	char	*dest;

	index = 0;
	dest = (char *)malloc(sizeof(*dest) * ft_strlen(src));
	if (!dest)
		return (NULL);
	while (index < size)
	{
		dest[index] = src[index];
		index++;
	}
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			index;
	int			total_len;
	t_stock_str	*table;

	index = 0;
	total_len = 0;
	while (index < ac)
	{
		total_len++;
		index++;
	}
	table = (t_stock_str *)malloc(sizeof(*table) * total_len);
	if (!table)
		return (NULL);
	index = 0;
	while (av[index])
	{
		total_len = ft_strlen(av[index]);
		table[index].copy = ft_strcpy(av[index], total_len);
		table[index].str = av[index];
		table[index].size = ft_strlen(av[index]);
		index++;
	}
	return (table);
}
