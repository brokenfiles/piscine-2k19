/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 21:03:25 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/08 14:00:58 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]))
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_putstr(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		write(1, &str[index], 1);
		index++;
	}
}

int		ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		index++;
	}
	return (index);
}

void	display_args(int index, char **argv, int argc)
{
	index = 1;
	while (index < argc)
	{
		ft_putstr(argv[index]);
		ft_putstr("\n");
		index++;
	}
}

int		main(int argc, char **argv)
{
	int		index;
	int		index2;
	char	*temp_string;

	index = 0;
	index2 = 0;
	while (index < argc - 1)
	{
		index2 = index + 1;
		while (index2 < argc)
		{
			if (ft_strcmp((char *)argv[index], (char *)argv[index2]) > 0)
			{
				temp_string = argv[index];
				argv[index] = argv[index2];
				argv[index2] = temp_string;
			}
			index2++;
		}
		index++;
	}
	index = 1;
	display_args(index, argv, argc);
}
