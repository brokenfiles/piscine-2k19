/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 12:08:16 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/11 15:33:49 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# define TRUE 1
# define FALSE 0
# define ERROR "Error\n"
# define SUCCESS 0
typedef struct	s_board
{
	int	*borders;
	int	**board;
}				t_board;
#endif
