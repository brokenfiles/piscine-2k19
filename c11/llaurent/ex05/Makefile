FILE_NAME = do-op
COMPILER = gcc
FLAGS = -Wall -Wextra -Werror
SRCS = ./ft_atoi.c ./ft_putnbr.c ./ft_putstr.c ./main.c ./operations.c
OBJS = ${SRCS:.c=.o}

all: ${FILE_NAME}

${FILE_NAME}: ${OBJS}
	${COMPILER} -o ${FILE_NAME} ${FLAGS} ${OBJS}

clean:
	rm -f ${OBJS}

fclean: clean 
	rm -f ${FILE_NAME}
