/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_output.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 16:00:03 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/11 21:13:17 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

char	*rev_str(char *string);
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(char *str);

int	has(int index, int line, char c, t_board *board)
{
	return (board->board[line][index] == c);
}

int	compare(char **output1, char **output2)
{
	int	index;
	int	index2;

	index = 0;
	index2 = 0;
	while (output1[index])
	{
		index2 = 0;
		while (output2[index2])
		{
			if (ft_strcmp(output1[index], rev_str(output2[index2])) == 0)
				return (1);
			index2++;
		}
		index++;
	}
	return (0);
}
