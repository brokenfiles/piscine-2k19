# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llaurent <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/12 12:23:53 by llaurent          #+#    #+#              #
#    Updated: 2019/08/19 10:30:28 by llaurent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

gcc -c ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c ft_atoi.c ft_split.c ft_strjoin.c -Wall -Wextra -Werror
ar rc libft.a ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o  ft_swap.o ft_atoi.c ft_split.c ft_strjoin.c
rm *.o
