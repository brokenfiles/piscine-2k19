/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychaver <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 11:21:18 by aychaver          #+#    #+#             */
/*   Updated: 2019/08/10 14:24:28 by aychaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_atoi(char *str);
int		ft_strlen(char *str);

int		*parse_args(char **av)
{
	int *res;
	int tr;
	int i;
	int j;

	i = 0;
	j = 0;
	if (ft_strlen(av[1]) != 31)
		return (NULL);
	if (!(res = malloc(16 * sizeof(int))))
		return (NULL);
	while (i < 16)
	{
		tr = ft_atoi(&av[1][j]);
		if (tr <= 4 && tr >= 1)
			res[i] = tr;
		else
			return (NULL);
		i++;
		j += 2;
	}
	return (res);
}
