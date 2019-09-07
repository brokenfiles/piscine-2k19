/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 18:11:46 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/17 19:34:40 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char			*ft_putnbr_base(int nbr, char *base_to);

int				ft_validbase(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[j] == base[i] || base[j] == '+' || base[j] == '-' ||
					(base[j] >= 9 && base[j] <= 13) || base[j] == ' ')
			{
				return (-1);
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (base[i] != '\0')
		i++;
	if (i < 2)
		return (-1);
	return (1);
}

int				ft_checkvalue(char *str, char *base)
{
	int j;

	j = 0;
	while (base[j] != '\0')
	{
		if (str[0] == base[j])
		{
			return (1);
		}
		j++;
	}
	return (-1);
}

int				ft_pos_in_base(char *str, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (str[0] == base[i])
		{
			return (i);
		}
		i++;
	}
	return (0);
}

unsigned int	ft_putstr_base(char *str, char *base)
{
	long	return_long;
	int		power;
	int		i;
	int		baselen;

	i = 0;
	return_long = 0;
	power = 1;
	baselen = 0;
	while (ft_checkvalue(&base[i], &base[i]) == 1)
	{
		baselen++;
		i++;
	}
	i = 0;
	while (ft_checkvalue(&str[++i], base) == 1)
		power *= baselen;
	i = 0;
	while (ft_checkvalue(&str[i], base) == 1)
	{
		return_long = return_long + ft_pos_in_base(&str[i], base) * power;
		i++;
		power /= baselen;
	}
	return (return_long);
}

char			*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		i;
	int		negative;
	int		rest;
	char	*output;

	i = 0;
	negative = 1;
	rest = 0;
	if (ft_validbase(base_from) == -1 || ft_validbase(base_to) == -1)
		return (0);
	while ((nbr[i] >= 9 && nbr[i] <= 13) || nbr[i] == ' ')
	{
		i++;
	}
	while (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
		{
			negative = negative * -1;
		}
		i++;
	}
	rest = (int)ft_putstr_base(&nbr[i], base_from) * negative;
	output = ft_putnbr_base(rest, base_to);
	return (output);
}
