/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 13:33:31 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/03 15:50:20 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	index;
	int	dest_counter;

	index = 0;
	dest_counter = 0;
	while (dest[dest_counter])
		dest_counter++;
	while (src[index])
	{
		dest[index + dest_counter] = src[index];
		index++;
	}
	dest[index + dest_counter] = 0;
	return (dest);
}
