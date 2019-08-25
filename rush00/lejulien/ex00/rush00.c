/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 08:37:03 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/03 12:12:40 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		is_at_borns(unsigned int i, unsigned int index)
{
	return ((index == 0) || (index == i - 1));
}

int		pos_in_line(unsigned int x, unsigned int index)
{
	if (index == 0)
		return (-1);
	else if (index == x - 1)
		return (1);
	else
		return (0);
}

void	print_vline(unsigned int x)
{
	unsigned int	index;

	index = 0;
	ft_putchar('\n');
	ft_putchar('*');
	x -= 2;
	while ((int)index < (int)x)
	{
		ft_putchar(' ');
		index++;
	}
	if ((int)x >= 2)
		ft_putchar('*');
}

void	print_hline(unsigned int x, unsigned int h_line)
{
	unsigned int	index;

	index = 0;
	while (index < x)
	{
		if (is_at_borns(x, index))
		{
			if (pos_in_line(x, index) == -1)
				ft_putchar((!h_line) ? '/' : '\\');
			if (pos_in_line(x, index) == 1)
				ft_putchar((!h_line) ? '\\' : '/');
		}
		else
		{
			ft_putchar('*');
		}
		index++;
	}
}

void	rush(unsigned int x, unsigned int y)
{
	unsigned int	index;
	unsigned int	h_line;

	h_line = 0;
	if ((int)x < 0)
		x *= -1;
	if ((int)y < 0)
		y *= -1;
	index = 0;
	print_hline(x, h_line);
	if (y >= 2)
	{
		y -= 2;
		while (index < y)
		{
			print_vline(x);
			index++;
		}
		ft_putchar('\n');
		print_hline(x, !h_line);
	}
}
