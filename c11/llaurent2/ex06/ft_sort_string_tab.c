/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 18:15:31 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/14 15:03:28 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	int	index;

	index = 0;
	while ((s1[index] && s2[index]) && (s1[index] == s2[index]))
		index++;
	return (s1[index] - s2[index]);
}

void	ft_swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_string_tab(char **tab)
{
	int		index;

	index = 0;
	while (tab[index + 1])
	{
		if (ft_strcmp(tab[index], tab[index + 1]) > 0)
		{
			ft_swap(&tab[index], &tab[index + 1]);
			index = 0;
		}
		else
			index++;
	}
}
