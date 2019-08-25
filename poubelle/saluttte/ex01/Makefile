LIB_NAME = libft.a
PATH_SRCS = srcs
PATH_HEADERS = includes
COMPILER_COMMAND = gcc
LIB_CREATOR_COMMAND = ar
RM_COMMAND = rm -f
FLAGS = -Wall -Wextra -Werror
OPTIONS = -I${PATH_HEADERS}
SRCS = ${PATH_SRCS}/ft_putchar.c ${PATH_SRCS}/ft_swap.c ${PATH_SRCS}/ft_putstr.c ${PATH_SRCS}/ft_strlen.c ${PATH_SRCS}/ft_strcmp.c
OBJS = ${SRCS:.c=.o}

all: ${LIB_NAME}

.c.o: ${OBJS}
	${COMPILER_COMMAND} ${OPTIONS} ${FLAGS} -c $< -o ${<:.c=.o}

${LIB_NAME}: ${OBJS}
	${LIB_CREATOR_COMMAND} rc ${LIB_NAME} ${OBJS}

clean:
	${RM_COMMAND} ${OBJS}

fclean: clean
	${RM_COMMAND} ${LIB_NAME}

re: fclean all

