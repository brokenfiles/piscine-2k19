/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 19:10:23 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/21 13:06:04 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/bsq.h"

char	*ft_strjoin(char *str1, char *str2)
{
	char	*res;
	int		len1;
	int		len2;
	int		i;

	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	if (!(res = (char *)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	i = 0;
	while (i < len1)
	{
		res[i] = str1[i];
		i++;
	}
	i = 0;
	while (i < len2)
	{
		res[len1 + i] = str2[i];
		i++;
	}
	res[len1 + i] = '\0';
	free(str1);
	return (res);
}
