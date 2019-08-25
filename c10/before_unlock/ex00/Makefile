# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llaurent <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/12 12:23:29 by llaurent          #+#    #+#              #
#    Updated: 2019/08/12 16:14:36 by llaurent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file
PATH_SRCS = srcs
PATH_HEADERS = includes
COMPILER_COMMAND = gcc
LIB_CREATOR_COMMAND = ar
RM_COMMAND = rm -f
OPTIONS = -I${PATH_HEADERS}
FLAGS = -Wall -Wextra -Werror
SRCS = ${PATH_SRCS}/ft_display_file.c
OBJS = ${SRCS:.c=.o}

all: ${NAME}

.c.o: ${OBJS}
	${COMPILER_COMMAND} ${OPTIONS} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${COMPILER_COMMAND} ${FLAGS} ${OBJS}
clean:
	${RM_COMMAND} ${OBJS}

fclean: clean
	${RM_COMMAND} ${LIB_NAME}

re: fclean all

