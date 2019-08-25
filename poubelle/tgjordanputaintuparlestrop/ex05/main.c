/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 17:04:40 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/13 22:15:13 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

int	do_op(int a, char divider, int b, int *result)
{
	if (divider == '+')
		*result = (plus(a, b));
	else if (divider == '-')
		*result = (less(a, b));
	else if (divider == '/')
	{
		if (b == 0)
			return (ERR_DIVIDE_BY_ZERO);
		*result = (divide(a, b));
	}
	else if (divider == '*')
		*result = (multiply(a, b));
	else if (divider == '%')
	{
		if (b == 0)
			return (ERR_MODULO_BY_ZERO);
		*result = (modulo(a, b));
	}
	return (SUCCESS);
}

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		index++;
	}
	return (index);
}

int	main(int ac, char **av)
{
	int	result;
	int	trace;

	if (ac < 4)
		return (ERR_ARGUMENTS);
	if (ft_strlen(av[2]) > 1)
	{
		ft_putnbr(0);
		ft_putstr("\n");
		return (ERR_ARGUMENTS);
	}
	trace = do_op(ft_atoi(av[1]), av[2][0], ft_atoi(av[3]), &result);
	if (trace != SUCCESS)
	{
		if (trace == ERR_DIVIDE_BY_ZERO)
			ft_putstr(MSG_ERR_DIVIDE_BY_ZERO);
		else if (trace == ERR_MODULO_BY_ZERO)
			ft_putstr(MSG_ERR_MODULO_BY_ZERO);
		return (trace);
	}
	ft_putnbr(result);
	write(1, "\n", 1);
	return (SUCCESS);
}
