/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 12:04:00 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/20 15:39:49 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"
#include <stdio.h>

int		f_size(char *file_name)
{
	int		index;
	char	buffer;
	int		fd;

	if ((fd = open(file_name, O_RDONLY)) == -1)
	{
		return (ERR_CANNOT_READ_MAP);
	}
	index = 0;
	while (read(fd, &buffer, 1) != 0)
	{
		index++;
	}
	close(fd);
	return (index);
}

char	*get_content(char *file_name)
{
	int		fd;
	char	buffer;
	char	*content;
	int		index;

	if (!(content = (char *)malloc(sizeof(char) * (f_size(file_name) + 1))))
		return (NULL);
	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (NULL);
	index = 0;
	while (read(fd, &buffer, 1) != 0)
	{
		content[index] = buffer;
		index++;
	}
	content[index] = 0;
	if (close(fd) == -1)
		return (NULL);
	return (content);
}

int		get_number_of_line(char *str, int *index)
{
	int	result;

	result = 0;
	while ((str[*index] >= 8 && str[*index] <= 13) || str[*index] == ' ')
		*index += 1;
	while (str[*index] >= '0' && str[*index] <= '9')
	{
		result = result * 10 + str[*index] - '0';
		*index += 1;
	}
	return (result);
}

t_data	get_data(char *map_content)
{
	t_data	data;
	char	**splitted;
	char	*first_line;
	int		index;

	index = 0;
	splitted = ft_split(map_content, "\n");
	first_line = splitted[0];
	data.line_num = get_number_of_line(first_line, &index);
	data.c_void = map_content[index++];
	data.c_obs = map_content[index++];
	data.c_full = map_content[index++];
	free(splitted);
	return (data);
}

int		get_map(int index, int number, char *file_name, t_map *map)
{
	char	*content;
	char	**splitted;

	if (!(content = get_content(file_name)))
		return (ERR_CANNOT_READ_MAP);
	map->data = get_data(content);
	if (map->data.line_num == 0)
		return (ERR_CANNOT_READ_MAP);
	splitted = ft_split(content, "\n");
	if (!(map->tab = (char **)malloc(sizeof(char *) * (map->data.line_num + 2))))
		return (ERR_CANNOT_READ_MAP);
	while (splitted[index])
	{
		if (number != ft_strlen(splitted[index]) && number != -1)
			return (ERR_CANNOT_READ_MAP);
		number = ft_strlen(splitted[index]);
		map->tab[index - 1] = ft_strdup(splitted[index]);
		index++;
	}
	if (map->data.line_num != index - 1)
		return (ERR_CANNOT_READ_MAP);
	map->tab[index - 1] = NULL;
	free(splitted);
	free(content);
	return (SUCCESS);
}
