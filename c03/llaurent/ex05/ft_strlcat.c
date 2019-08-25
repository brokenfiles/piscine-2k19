/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 13:51:07 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/03 21:16:55 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	index;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size == 0)
		return (dest_len);
	if (size < dest_len)
		src_len += size;
	else
		src_len += dest_len;
	index = 0;
	while (src[index] && ((dest_len + index) < size - 1))
	{
		dest[index + dest_len] = src[index];
		index++;
	}
	dest[index + dest_len] = '\0';
	return (src_len);
}
