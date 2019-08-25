/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 08:20:19 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/01 17:06:38 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	bonjour;

	bonjour = 'a';
	while (bonjour <= 'z')
	{
		write(1, &bonjour, 1);
		bonjour++;
	}
}

int	main(void)
{
	ft_print_alphabet();
	return (0);
}

