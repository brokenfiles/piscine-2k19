/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 11:19:27 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/13 11:19:57 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rush.h"

void	ft_putstr(char *str);
int		*parse_args(char **av);
void	display_board(t_board board);
int		ft_strlen(char *str);
void	ft_putnbr(int nbr);
int		**double_proposition(int start, int end);
char	**ft_split(char *str, char *charset);
int		ft_atoi(char *str);
char	*give_proposition(int index);
void	ft_rev_int_tab(int *tab, int size);
int		compare(char **output1, char **output2);

int	line;

int		tab_len(char **tab)
{
	int	index;

	index = 0;
	while (tab[index])
	{
		index++;
	}
	return (index);
}

int		set_line(t_board *board, int index)
{
	char *str;
	int	index2;
	int	index3;
	int	prop_len;
	char **output;
	char **output2;
	char **output3;
	
	str = give_proposition(board->borders[index + 8]);
	output = ft_split(str, ";");
	if (ft_strlen(str) == 0)
		return (FALSE);
	prop_len = tab_len(output);
	if (prop_len > 0)
	{
		index2 = 0;
		while (index2 < prop_len)
		{
			line = index;
			output2 = ft_split(output[index2], ",");
			index3 = 0;
			output3 = ft_split(give_proposition(
						board->borders[index + 12]), ";");
			while (output2[index3])
			{
				board->board[index][index3] = ft_atoi(output2[index3]);
				index3++;
			}
			if (compare(output, output3))
			{
				return (TRUE);
			}
			else
				return (FALSE);
			index2++;
		}
	}
	return (TRUE);
}

int		init(t_board *board)
{
	int	index;

	index = 0;
	board->board = (int **)malloc(sizeof(int *) * 4);
	while (index < 4)
	{
		board->board[index] = (int *)malloc(sizeof(int) * 4);
		if (!set_line(board, index))
			return (FALSE);
		index++;
	}
	return (TRUE);
}

int		main(int ac, char **av)
{
	t_board board;

	if (ac < 2)
	{
		ft_putstr(ERROR);
		return (FALSE);
	}
	if ((board.borders = parse_args(av)) == NULL)
	{
		ft_putstr(ERROR);
		return (FALSE);
	}
	if (!(init(&board)))
	{
		ft_putstr(ERROR);
		return (FALSE);
	}
	display_board(board);
	return (TRUE);
}
