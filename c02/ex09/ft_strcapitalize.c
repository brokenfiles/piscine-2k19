/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 18:22:27 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/08 20:54:12 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	char	*tmp;

	tmp = str;
	if (*tmp >= 'a' && *tmp <= 'z')
		*tmp = 'A' + *tmp - 'a';
	while (*tmp != '\0')
	{
		if (!((*tmp >= 'a' && *tmp <= 'z')
					|| (*tmp >= 'A' && *tmp <= 'Z')
					|| (*tmp >= '0' && *tmp <= '9'))
				&& *(tmp + 1) != '\0'
				&& (*(tmp + 1) >= 'a' && *(tmp + 1) <= 'z'))
		{
			*(tmp + 1) = 'A' + *(tmp + 1) - 'a';
		}
		if (((*tmp >= 'a' && *tmp <= 'z') || (*tmp >= 'A' && *tmp <= 'Z'))
				&& ((*(tmp - 1) >= 'a' && *(tmp - 1) <= 'z')
					|| (*(tmp - 1) >= 'A' && *(tmp - 1) <= 'Z')
					|| (*(tmp - 1) >= '0' && *(tmp - 1) <= '9')))
			if (*tmp >= 'A' && *tmp <= 'Z')
				*tmp = 'a' + *tmp - 'A';
		tmp++;
	}
	return (str);
}
