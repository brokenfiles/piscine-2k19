/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychaver <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 12:09:30 by aychaver          #+#    #+#             */
/*   Updated: 2019/08/11 16:50:29 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_row(int **board, int x, int y)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (board[i][y] == board[x][y] && i != x)
			return (1);
		else
			i++;
	}
	return (0);
}

int		is_column(int **board, int x, int y)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (board[x][i] == board[x][y] && i != y)
			return (1);
		else
			i++;
	}
	return (0);
}

void	check_row1(int **board, int *i, int y, int *buff)
{
	int max;

	while (*i < 4)
	{
		if (i == 0)
			max = board[*i][y];
		else if (board[*i][y] > max)
		{
			max = board[*i][y];
			*buff += 1;
		}
		*i += 1;
	}
}

void	check_row2(int **board, int *i, int y, int *buff)
{
	int max;

	while (*i < 4)
	{
		if (*i == 3)
			max = board[*i][y];
		else if (board[*i][y] > max)
		{
			max = board[*i][y] > max;
			*buff += 1;
		}
		*i += 1;
	}
}

int		is_row_valid(int **board, int *borders, int y)
{
	int i;
	int buff;

	i = 0;
	buff = 1;
	while (i < 4)
	{
		if (is_row(board, i, y) == 0)
			i++;
		else
			return (0);
	}
	i = 0;
	check_row1(board, &i, y, &buff);
	if (buff == borders[8 + y])
	{
		i--;
		buff = 1;
		check_row2(board, &i, y, &buff);
		if (buff == borders[12 + y])
			return (1);
	}
	return (0);
}
