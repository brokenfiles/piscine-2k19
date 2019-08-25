/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 14:23:27 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/03 15:53:57 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	index;
	unsigned int	dest_counter;

	index = 0;
	dest_counter = 0;
	while (dest[dest_counter])
		dest_counter++;
	while (src[index] && (index < nb))
	{
		dest[index + dest_counter] = src[index];
		index++;
	}
	dest[index + dest_counter] = 0;
	return (dest);
}
