# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: henkaoua <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 13:33:25 by henkaoua          #+#    #+#              #
#    Updated: 2021/11/11 16:20:36 by henkaoua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_printf.c print_hex.c print_int.c

NAME	= libftprintf.a
FLGS	= -Wall -Wextra -Werror
OBJS	= ${SRCS:.c=.o}
GCC		= gcc
RM		= rm -f
AR		= ar rc
RAN		= ranlib

all:		${NAME}

.c.o:
			${GCC} ${FLGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}
			${RAN} ${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all fclean clean re

