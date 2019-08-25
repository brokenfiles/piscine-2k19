/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 14:32:55 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/12 11:57:46 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		in_charset(char c, char *charset)
{
	if (*charset == '\0' || charset == NULL)
		return (0);
	while (*charset)
	{
		if (*charset++ == c)
			return (1);
	}
	return (0);
}

int		get_wordsize(char *str, char *charset)
{
	int	size;

	size = 0;
	while (!in_charset(*str++, charset) && *str)
		size++;
	return (size);
}

char	*copy_word(char *str, char *charset)
{
	int		size;
	char	*tab_line;

	size = get_wordsize(str, charset);
	if ((tab_line = malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	size = 0;
	while (!in_charset(*str, charset) && *str)
	{
		tab_line[size] = *str++;
		size++;
	}
	tab_line[size] = '\0';
	return (tab_line);
}

char	**set_table(char *str, char *charset, char **tab)
{
	int	index;
	int	ret_i;

	ret_i = 0;
	index = 0;
	while (*str)
	{
		if (!in_charset(*str, charset) && !ret_i)
		{
			tab[index] = copy_word(&*str, charset);
			tab[index + 1] = 0;
			if (tab[index] == NULL)
				return (NULL);
			ret_i = 1;
		}
		if (in_charset(*str++, charset) && ret_i)
		{
			index++;
			ret_i = 0;
		}
	}
	return (tab);
}

char	**ft_split(char *str, char *charset)
{
	int		size;
	int		check;
	char	*last_str;
	char	**returned_tab;

	check = 0;
	size = 0;
	if (str == NULL || str[0] == '\0')
		return (NULL);
	last_str = str;
	while (*str)
	{
		if (!in_charset(*str, charset) && check == 0)
		{
			size++;
			check = 1;
		}
		if (in_charset(*str++, charset))
			check = 0;
	}
	if ((returned_tab = malloc(sizeof(char *) * (size + 1))) == NULL ||
			size == 0)
		return (NULL);
	returned_tab = set_table(last_str, charset, returned_tab);
	return (returned_tab);
}
