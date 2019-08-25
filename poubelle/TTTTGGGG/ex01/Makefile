# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llaurent <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/12 12:23:29 by llaurent          #+#    #+#              #
#    Updated: 2019/08/15 16:05:33 by llaurent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_cat
PATH_SRCS = srcs
PATH_HEADERS = includes
COMPILER_COMMAND = gcc
RM_COMMAND = rm -f
OPTIONS = -I${PATH_HEADERS}
FLAGS = -Wall -Wextra -Werror
SRCS = ${PATH_SRCS}/ft_cat.c ${PATH_SRCS}/ft_putstr.c ${PATH_SRCS}/ft_display_error.c
OBJS = ${SRCS:.c=.o}

all: ${NAME}

.c.o: ${OBJS}
	${COMPILER_COMMAND} ${OPTIONS} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${COMPILER_COMMAND} ${FLAGS} ${OBJS} -o ${NAME}
clean:
	${RM_COMMAND} ${OBJS}

fclean: clean
	${RM_COMMAND} ${NAME}

re: fclean all

