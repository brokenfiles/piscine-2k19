/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 16:18:08 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/22 14:47:07 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	char_to_hex(char c)
{
	char	hex[2];

	if ((c % 16) < 10)
		hex[1] = '0' + (c % 16);
	else
		hex[1] = 'a' + (c % 16) - 10;
	if ((c / 16) < 10)
		hex[0] = '0' + (c / 16);
	else
		hex[0] = 'a' + (c / 16) - 10;
	write(1, &hex, 2);
}

void	print_addr(char *ptr)
{
	int		addr;
	int		index;
	char	hex[15];

	addr = (int)ptr;
	index = -1;
	while (++index < 15)
		hex[index] = '0';
	index = 14;
	while (addr)
	{
		if ((addr % 16) < 10)
			hex[index] = '0' + (addr % 16);
		else
			hex[index] = 'a' + ((addr % 16) - 10);
		addr /= 16;
		index--;
	}
	write(1, &hex, 15);
	write(1, ": ", 2);
}

void	print_raw_val(char *ptr, unsigned int size)
{
	unsigned int	index;

	index = 0;
	while (index < 16)
	{
		if (index >= size)
			write(1, "  ", 2);
		else
			char_to_hex(ptr[index]);
		if (index % 2 == 1)
			write(1, " ", 1);
		index++;
	}
}

void	print_val(char *str, unsigned int size)
{
	unsigned int	index;

	index = 0;
	while (index < size)
	{
		if (str[index] >= ' ' && str[index] <= '~')
			write(1, &str[index], 1);
		else
			write(1, ".", 1);
		index++;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	index;
	unsigned int	tmp;
	char			*ptr;

	index = 0;
	ptr = (char*)addr;
	while (size)
	{
		if (size > 16)
			tmp = 16;
		else
			tmp = size;
		print_addr(&ptr[index]);
		print_raw_val(&ptr[index], tmp);
		print_val(&ptr[index], tmp);
		index += 16;
		if (size < 16)
			size = 0;
		else
			size -= 16;
	}
	return (addr);
}
