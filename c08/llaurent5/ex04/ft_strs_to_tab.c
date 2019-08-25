/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 11:56:52 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/15 17:21:43 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int	i;
	char*dest;

	i = 0;
	dest = (char *)malloc(sizeof(*dest) * (1 + ft_strlen(src)));
	if (dest == 0)
		return (0);
	while ((dest[i] = src[i]))
	{
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int	i;
	struct s_stock_str	*tab;

	i = 0;
	if ((tab = (struct s_stock_str*)malloc(sizeof(struct s_stock_str) * (ac + 1))) == NULL)
		return (0);
	while (i < ac)
	{
		tab[i].size = ft_strlen(av[i]);
		tab[i].str = ft_strdup(av[i]);
		tab[i].copy = ft_strcpy(av[i], tab[i].str);
		i++;
	}
	tab[i].str = 0;
	return (tab);
}
