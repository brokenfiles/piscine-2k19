/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 19:10:23 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/09 15:02:17 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

void	ft_strcat(char *dest, char *src)
{
	int	index;
	int	dest_len;

	dest_len = 0;
	index = 0;
	while (dest[dest_len])
		dest_len++;
	while (index < ft_strlen(src) + 1)
	{
		dest[index + dest_len] = src[index];
		index++;
	}
}

char*	ft_strjoin(int size, char **strs, char *sep)
{
	int		total_len;
	int		index;
	char*	returned_str;

	total_len = 0;
	index = 0;
	while (index < size)
	{
		if (index != size - 1)
			total_len += ft_strlen(sep);
		total_len = total_len + ft_strlen(strs[index]);
		index++;
	}
	index = 0;
	if (size == 0)
		return ((char *)malloc(sizeof(char *)));
	returned_str = (char *)malloc(sizeof(*returned_str) * ((total_len) + 1));
	while (strs[index])
	{
		ft_strcat(returned_str, strs[index]);
		if (size != 0 && index + 1 != size)
			ft_strcat(returned_str, sep);
		index++;
	}
	return (returned_str);
}

int	main(int argc, char **argv)
{
	char *returned_str = ft_strjoin(argc - 2, argv + 2, argv[1]);
	printf("%s\n", returned_str);
}
