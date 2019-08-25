/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 18:22:27 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/01 21:44:38 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*first_char_toupper(char *str)
{
	if (str[0])
	{
		if (str[0] >= 97 && str[0] <= 122)
			str[0] -= 32;
	}
	return (str);
}

int		is_before_word(int c)
{
	return ((c >= 0 && c <= 32) || (c >= 33 && c <= 47) ||
			(c >= 58 && c <= 64) || (c >= 91 && c <= 96) ||
			(c >= 123 && c <= 127));
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	c;

	first_char_toupper(str);
	i = 0;
	while (str[i])
	{
		c = str[i];
		if (i == 0)
		{
			if (c >= 97 && c <= 122)
				str[i] -= 32;
		}
		if (is_before_word(c))
		{
			if (str[i + 1])
			{
				c = str[i + 1];
				if (c >= 97 && c <= 122)
					str[i + 1] -= 32;
			}
		}
		i++;
	}
	return (str);
}
