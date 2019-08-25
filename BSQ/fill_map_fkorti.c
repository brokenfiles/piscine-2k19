/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 14:19:21 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/21 14:54:53 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"
#include <stdio.h>

typedef struct s_pos
{
	int x;
	int y;
	int value;
} t_pos;

int **ft_big(char **tab, int **fake, t_map *info, int line_col)
{
	int i;
	int y;
	int zero;
	zero = 0;
	y = 0;
	while(y < info->data.line_num)
	{
		i = 0;
		while(i < line_col)
		{
			if(tab[y][i] == info->data.c_obs)
				fake[y][i] = zero;
			else
				fake[y][i] = 1;
			i++;
		}
		y++;
	}

	return(fake);
}

int check_smallest(int posx, int posy, int posz)
{
	int sort[3];
	int swap;
	int i;

	i = 0;
	sort[0] = posx;
	sort[1] = posy;
	sort[2] = posz;
	while(i < 2)
	{
		if (sort[i] > sort[i + 1])
		{
			swap = sort[i];
			sort[i] = sort[i + 1];
			sort[i + 1] = swap;
			i = 0;
		}
		else
			i++;
	}
	return(sort[0] + 1);
}

void ft_awesome(int **fake, t_map *info, int line_col)
{
	int	y = 1;
	int i;
	int posx;
	int posz;
	int posy;
	int smallest;
	while(y < info->data.line_num)
	{
		i = 1;
		while(i < line_col)
		{
			posx = fake[y - 1][i];
			posy = fake[y][i - 1];
			posz = fake[y - 1][i - 1];
			smallest = check_smallest(posx, posy, posz);
			if (fake[y][i] != 0)
				fake[y][i] = smallest;
			i++;
		}
		y++;
	}
}

void ft_mod_origin(int **fake, char **tab, t_pos point, t_map *info, char **finish, int line_col)
{
	int j;
	int i;
	j = 0;
	while(j < info->data.line_num)
	{
		i = 0;
		while(i < line_col)
		{
			if((j > point.y - point.value) && (j <= point.y) && (i > point.x - point.value) && (i <= point.x))
			{
				finish[j][i] = info->data.c_full;
			}
			else
			{
				finish[j][i] = tab[j][i];
			}
			i++;
		}
		j++;
	}
}

struct s_pos	ft_find_biggist(int **fake, t_map *info, int line_col)
{
	int y;
	int i;
	int big;
	struct s_pos point;

	y = 0;
	point.value = fake[0][0];
	while(y < info->data.line_num)
	{
		i = 0;
		while(i < line_col)
		{
			if (fake[y][i + 1] > point.value && fake[y][i <  line_col - 1])
			{
				point.x = i + 1;
				point.y = y;
				point.value = fake[y][i + 1];
			}
			i++;
		}
		y++;
	}

	return (point);
}

void ft_hub(t_map *map)
{
	int size;
	int X;
	char **tab;
	int **fake;
	char **finish;
	int i;
	int y;
	struct s_pos point;
	int	len;

	i = 0;
	size = map->data.line_num;
	len = ft_strlen(map->tab[0]);
	tab = malloc(sizeof(char*) * size + 1);
	while(i < size)
	{
		tab[i] = malloc(sizeof(char) * len  + 1);
		i++;
	}
	fake = malloc(sizeof(int*) * size + 1);
	i = 0;
	while(i < size)
	{
		fake[i] = malloc(sizeof(int) * len + 1);
		i++;
	}
	finish = malloc(sizeof(char*) * size + 1);
	i = 0;
	while(i < size)
	{
		finish[i] = malloc(sizeof(char) * len + 1);
		i++;
	}

	i = 0;
	fake = ft_big(map->tab, fake, map, len);
	ft_awesome(fake, map, len);
	point = ft_find_biggist(fake, map, len);
	ft_mod_origin(fake, map->tab, point, map, finish, len);
	y = 0;
	while(y < map->data.line_num)
	{
		i = 0;
		while(i < len)
		{
			map->tab[y][i] = finish[y][i];
			i++;
		}
		y++;
	}
	free(finish);
	free(fake);
	free(tab);
}
