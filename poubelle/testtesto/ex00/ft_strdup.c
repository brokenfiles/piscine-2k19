/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 20:55:18 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/08 15:05:04 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *src)
{
	int	index;

	index = 0;
	while (src[index])
		index++;
	return (index);
}

char	*ft_strdup(char *src)
{
	int		len;
	char	*str;
	int		index;

	index = 0;
	len = ft_strlen(src);
	if ((str = (char *)malloc(sizeof(*src) * (len + 1))) == NULL)
		return (NULL);
	while (index < len)
	{
		str[index] = src[index];
		index++;
	}
	str[index] = '\0';
	return (str);
}
