/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 19:10:23 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/08 17:03:26 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		index++;
	}
	return (index);
}

int		ft_total_len(char **strs, char *sep, int size)
{
	int index;
	int index2;
	int nbr;

	nbr = 0;
	index2 = 0;
	index = 0;
	while (index2 < size)
	{
		nbr += ft_strlen(strs[index2]);
		index2++;
	}
	index2 = 0;
	while (sep[index++])
		index2++;
	if (size > 0)
		nbr = nbr + index2 * (size - 1);
	return (nbr);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		len;
	int		index;
	int		index2;
	int		index3;
	char	*dest;

	if (size <= 0)
		return (malloc(sizeof(char)));
	len = ft_total_len(strs, sep, size);
	if ((dest = malloc(sizeof(char) * (len + 1))) == NULL)
		return (0);
	index = 0;
	index2 = 0;
	while (size > 0)
	{
		index3 = 0;
		while (strs[index2][index3])
			dest[index++] = strs[index2][index3++];
		index3 = 0;
		if (size-- != 1 && ++index2)
			while (sep[index3])
				dest[index++] = sep[index3++];
	}
	dest[index] = '\0';
	return (dest);
}
