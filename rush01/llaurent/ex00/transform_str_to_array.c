/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_str_to_array.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 15:52:13 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/11 15:59:58 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char **ft_split(char *str, char *charset);

char **transform_str_to_array(char *str)
{
	char	**output;

	output = ft_split(str, ";");
	return (output);
}
