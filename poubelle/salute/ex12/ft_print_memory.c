/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 16:18:08 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/20 18:06:17 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_hexa(char str)
{
	int		div;
	int		mod;
	char	*baseh;

	baseh = "0123456789abcdef";
	div = str / 16;
	mod = str % 16;
	write(1, &baseh[div], 1);
	write(1, &baseh[mod], 1);
}

void	putchar(char c)
{
	write(1, &c, 1);
}

void	ft_hexalong(unsigned long int nbr)
{
	char	*baseh;
	int		mod;

	baseh = "0123456789abcdef";
	if (nbr > 16)
	{
		ft_hexalong(nbr / 16);
		mod = nbr % 16;
		putchar(baseh[mod]);
	}
	else
		putchar(baseh[nbr]);
}

void	ft_print_memory2(int *k, int *j, int *i, char *chaine)
{
	while (*k / 16 < *j)
	{
		if (chaine[*k] > 1)
			ft_hexa(chaine[*k]);
		else
			write(1, "  ", 2);
		if ((*k + 1) % 2 == 0)
			write(1, " ", 1);
		*k += 1;
	}
	while (*i / 16 < *j && chaine[*i] != '\0')
	{
		if (chaine[*i] >= 32 && chaine[*i] < 127)
			write(1, &chaine[*i], 1);
		else
			write(1, ".", 1);
		*i += 1;
	}
}

void	ft_print_memory(void *addr, unsigned int size)
{
	int					i;
	int					j;
	int					k;
	char				*chaine;
	unsigned long int	addresse;

	chaine = (char *)addr;
	i = 0;
	j = 1;
	k = 0;
	size = 0;
	while (chaine[i] != '\0')
	{
		write(1, "000000", 6);
		addresse = (unsigned long int)(chaine + i);
		ft_hexalong(addresse);
		write(1, ": ", 2);
		ft_print_memory2(&k, &j, &i, chaine);
		write(1, "\n", 1);
		j++;
	}
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
	ft_print_memory(av[1], ft_strlen(av[1]));
}
