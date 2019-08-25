/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 14:19:21 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/21 16:47:31 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"
#include <stdio.h>

int		val_abs(int val)
{
	if (val < 0)
		val *= -1;
	return (val);
}

int		check_posi(int *tab, char **carte, char c_obs)
{
	int i;
	int j;

	i = tab[2];
	j = tab[1];
	while (j < tab[1] + tab[0])
	{
		while (i < tab[2] + tab[0])
		{
			if (carte[j][i] == c_obs)
				return (0);
			i++;
		}
		i = tab[2];
		j++;
	}
	return (1);
}

void	print_table(int *tab)
{
	int i;
	int val;

	i = 0;
	while (i < 3)
	{
		val = tab[i] + 48;
		//write(1, &val, 1);
		i++;
	}
}

int		*inc(int n, int *tab, char **carte, t_map *map, int line_len)
{
	int			size;
	int     	pos;
	static int	flag;

	flag = 0;
	size = (line_len <= map->data.line_num ? line_len : map->data.line_num);
	pos = 0;
	while (size >= 0 && pos <= (map->data.line_num >= line_len ? map->data.line_num : line_len) && flag == 0)
	{
		if (n == 0)
			tab[n] = size;
		else
			tab[n] = pos;
		if (n < 2) //&& check_posi(tab, n))
			inc(n + 1, tab, carte, map, line_len);
		else if (tab[1] + tab[0] <= map->data.line_num && tab[2] + tab[0] <= line_len && check_posi(tab, carte, map->data.c_obs))
		{
			flag = 1;
			return (0);
		}
		if (n == 0)
			size--;
		pos++;
	}
	return (tab);
}

int		*bsq(t_map *map, int line_len)
{
	int *tab;
	tab = malloc(sizeof(int) * 3);
	return (inc(0, tab, map->tab, map, line_len));
}

int		fill_map(t_map *map)
{
	int		line_len;
	int		*tab;
	int		x;
	int		y;
	int		size;

	line_len = ft_strlen(map->tab[0]);
	tab = bsq(map, line_len);
	size = tab[0];
	x = tab[2];
	y = tab[1];
	while (y < tab[1] + (size))
	{
		x = tab[2];
		while (x < tab[2] + (size))
		{
			map->tab[y][x] = map->data.c_full;
			x++;
		}
		y++;
	}
	return (SUCCESS);
}
