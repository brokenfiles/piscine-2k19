/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_board.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 13:11:13 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/10 16:24:23 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	ft_putstr(char *str);
void	ft_putnbr(int nbr);

void	display_board(t_board board)
{
	int	index;
	int	index2;

	index = 0;
	index2 = 0;
	while (index < 4)
	{
		index2 = 0;
		while (index2 < 4)
		{
			ft_putnbr(board.board[index][index2]);
			ft_putstr(" ");
			index2++;
		}
		ft_putstr("\n");
		index++;
	}
}
