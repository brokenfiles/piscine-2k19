/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 11:56:52 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/08 12:32:28 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_stock_str.h"

int					ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		index++;
	}
	return (index);
}

char				*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	if ((dest = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1))) == NULL)
		return (NULL);
	dest[ft_strlen(src)] = '\0';
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str	*tab;

	i = -1;
	tab = (struct s_stock_str*)malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (tab == NULL)
		return (NULL);
	tab[ac].str = 0;
	while (++i < ac)
	{
		tab[i].size = ft_strlen(av[i]);
		tab[i].str = av[i];
		tab[i].copy = ft_strcpy(tab[i].copy, av[i]);
	}
	return (tab);
}

int					main(int argc, char **argv)
{
	struct s_stock_str	*tab;
	int					index;

	index = 0;
	tab = ft_strs_to_tab(argc, argv);
	if (tab == 0)
		return (0);
	while (index < argc)
	{
		printf("%s\n", tab[index].str);
		printf("%d\n", tab[index].size);
		printf("%s\n", tab[index].copy);
		index++;
	}
	return (0);
}
