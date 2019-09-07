/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 18:00:21 by llaurent          #+#    #+#             */
/*   Updated: 2019/08/13 18:59:42 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H

# include <unistd.h>
# define ERR_DIVIDE_BY_ZERO 1
# define ERR_MODULO_BY_ZERO 2
# define ERR_ARGUMENTS 3
# define MSG_ERR_DIVIDE_BY_ZERO "Stop : division by zero\n"
# define MSG_ERR_MODULO_BY_ZERO "Stop : modulo by zero\n"
# define SUCCESS 0

int		plus(int a, int b);
int		less(int a, int b);
int		divide(int a, int b);
int		multiply(int a, int b);
int		modulo(int a, int b);
void	ft_putstr(char *str);
void	ft_putnbr(int nbr);
int		ft_atoi(char *str);
#endif
