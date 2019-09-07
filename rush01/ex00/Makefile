# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llaurent <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/10 11:20:26 by llaurent          #+#    #+#              #
#    Updated: 2019/08/10 11:30:54 by llaurent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-01
RM_COMMAND = rm -f
COMPILER = cc
FLAGS = -Wall -Wextra -Werror

${NAME}:
	${COMPILER} ${FLAGS} -o ${NAME} *.c

clean: 
	${RM_COMMAND} ${NAME}

re: clean ${NAME}
