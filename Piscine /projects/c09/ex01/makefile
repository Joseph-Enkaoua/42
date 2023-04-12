#include <includes/ft.h>

SRCS = ${addprefix ./srcs/, ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c}

OBJS = ${SRCS:.C=.O}

CC = gcc -o -Wall -Wextra -Werror 

RM = rm -f

NAME = libft.a

AR = ar rc

RN = ranlib

${NAME}:	${SRCS}
			${CC} ${NAME} ${OBJS}
			${AR} ${NAME} ${OBJS}
			${RN} ${NAME}

all:		${NAME}

clean:
			${RN} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
