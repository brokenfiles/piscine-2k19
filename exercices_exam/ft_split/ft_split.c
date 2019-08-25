/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 20:31:22 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/22 20:40:44 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		count_words(char *str)
{
	int	index;
	int	words;
	int	new_word;

	new_word = 0;
	words = 0;
	index = 0;
	while (str[index] == ' ' || str[index] == '\t')
		index++;
	while (str[index])
	{
		if (str[index] != ' ' && str[index] != '\t' && !new_word)
		{
			new_word = 1;
			words++;
		}
		if (str[index] == ' ' || str[index] == '\t')
		{
			new_word = 0;
			index++;
		}
		index++;
	}
	return (words);
}

char	**ft_split(char *str)
{
	int		index;
	char	**splitted;

	index = 0;
	
	return (splitted);
}
