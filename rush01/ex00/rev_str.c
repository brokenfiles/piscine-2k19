/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 16:17:57 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/11 16:27:57 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);

char *rev_str(char *string)
{
	char *ret_val;
	int i;

	ret_val = (char *)malloc(sizeof(*ret_val) * (ft_strlen(string) + 1));
	i = 0;
	while(string[i])
	{
		ret_val[i] = string[ft_strlen(string) - i - 1];
		i++;
	}
	return (ret_val);
}
