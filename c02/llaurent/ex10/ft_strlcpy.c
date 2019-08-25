/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 18:30:54 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/01 21:48:40 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int counter;

	i = 0;
	counter = 0;
	while (dest[counter])
	{
		counter++;
	}
	while (src[i] && i < size)
	{
		dest[i + counter] = src[i];
		i++;
	}
	i = 0;
	dest[i + counter] = '\0';
	return (i + counter);
}
