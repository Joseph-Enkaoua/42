NAME	= philo
SRCS	= main.c thread_actions.c utils.c
FLGS	= -Wall -Wextra -Werror
OBJS	= ${SRCS:.c=.o}
CC		= gcc
RM		= rm -f

all:	${NAME}

${NAME}:	${OBJS}
		${CC} ${FLGS} ${OBJS} -o ${NAME}

.c.o:
		${CC} ${FLGS} -c $< -o ${<:.c=.o}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
