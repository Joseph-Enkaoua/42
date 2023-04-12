# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: henkaoua <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/14 13:54:16 by henkaoua          #+#    #+#              #
#    Updated: 2022/01/14 14:32:31 by henkaoua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_SRCS	= server.c
CLIENT_SRCS	= client.c
SERVER_NAME	= server
CLIENT_NAME	= client
FLGS		= -Wall -Wextra -Werror
SERVER_OBJS	= ${SERVER_SRCS:.c=.o}
CLIENT_OBJS	= ${CLIENT_SRCS:.c=.o}
GCC		= gcc
RM		= rm -f

all:			${SERVER_OBJS} ${CLIENT_OBJS} ${SERVER_NAME} ${CLIENT_NAME}

.c.o:
				${GCC} ${FLGS} -c $< -o ${<:.c=.o}

${SERVER_NAME}:	
						${GCC} ${FLGS} -o ${SERVER_NAME} ${SERVER_OBJS}

${CLIENT_NAME}:	
						${GCC} ${FLGS} -o ${CLIENT_NAME} ${CLIENT_OBJS}

clean:
						${RM} ${SERVER_OBJS} ${CLIENT_OBJS}

fclean:			clean					
						${RM} ${SERVER_NAME}
						${RM} ${CLIENT_NAME}

re:				fclean all

.PHONY:			all fclean clean re
