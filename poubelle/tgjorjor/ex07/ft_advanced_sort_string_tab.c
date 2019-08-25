/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 18:47:10 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/13 21:35:12 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int		tab_len(char **tab)
{
	int	index;

	index = 0;
	while (tab[index])
		index++;
	return (index);
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		index;

	index = 0;
	while (index < tab_len(tab) - 1)
	{
		if ((*cmp)(tab[index], tab[index + 1]) > 0)
		{
			ft_swap(&tab[index], &tab[index + 1]);
			index = 1;
		}
		else
			index++;
	}
}
