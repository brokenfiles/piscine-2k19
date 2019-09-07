/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychaver <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 13:16:41 by aychaver          #+#    #+#             */
/*   Updated: 2019/08/10 15:36:10 by aychaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_column(int **boards, int x, int y);

void	check_column1(int **board, int *i, int x, int *buff)
{
	int max;

	while (*i < 4)
	{
		if (i == 0)
			max = board[x][*i];
		else if (board[x][*i] > max)
		{
			max = board[x][*i];
			*buff += 1;
		}
		*i += 1;
	}
}

void	check_column2(int **board, int *i, int x, int *buff)
{
	int max;

	while (*i < 4)
	{
		if (*i == 3)
			max = board[x][*i];
		else if (board[x][*i] > max)
		{
			max = board[x][*i] > max;
			*buff += 1;
		}
		*i += 1;
	}
}

int		is_column_valid(int **board, int *borders, int x)
{
	int i;
	int buff;
	int max;

	i = 0;
	buff = 1;
	while (i < 4)
	{
		if (is_column(board, x, i) == 0)
			i++;
		else
			return (0);
	}
	i = 0;
	check_column1(board, &i, x, &buff);
	if (buff == borders[0 + x])
	{
		i--;
		buff = 1;
		check_column2(board, &i, x, &buff);
		if (buff == borders[4 + x])
			return (1);
	}
	return (0);
}
