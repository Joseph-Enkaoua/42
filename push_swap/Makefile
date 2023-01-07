# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddordain <ddordain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/29 17:31:17 by ddordain          #+#    #+#              #
#    Updated: 2022/02/15 17:59:14 by henkaoua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean re fclean

NAME = push_swap
LIBFT = libft.a
LIB_DIR = libft/
OBJ_DIR = obj/
SRCS_DIR = src/
SRCS = main.c error_management.c algorithm_1.c algorithm_2.c algorithm_3.c operators_1.c operators_2.c operators_3.c

OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

LFLAGS = -I include/
CFLAGS = -Wall -Wextra -Werror
DEBUGGING = -ggdb
CC = gcc
RM = rm -rf
AR = ar rc
RESET = \033[0m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
PINK = \033[35m
CYAN = \033[36m

all: $(NAME)

$(OBJ_DIR)%.o : $(SRCS_DIR)%.c
		@echo Create: $(NAME) Object directory
		@mkdir -p $(OBJ_DIR)
		$(CC) -c $(CFLAGS) $(DEBUGGING) $(LFLAGS) $< -o $@

$(NAME): $(OBJS)
		@echo "$(CYAN)=========== Compilation $(LIBFT) ==========="
		make -C $(LIB_DIR)
		@echo "=========== DONE ==========$(RESET)"

		@echo "$(YELLOW)=========== Compilation $(NAME) ==========="
		$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) $(LIB_DIR)$(LIBFT) -o $(NAME)
#		$(CC)$(CFLAGS) $(LFLAGS) $(LIB_DIR)$(LIBFT) -o $(NAME) $(OBJS)
		@echo "=========== DONE ==========$(RESET)"

clean:
		@echo "$(PINK)========== CLEAN =========="
		$(RM) $(OBJ_DIR)
		$(RM) $(OBJS)
		make -C $(LIB_DIR) clean
		@echo "$(PINK)=========== DONE ===========$(RESET)"
fclean: clean
		@echo "$(RED)========== FCLEAN =========="
		$(RM) $(NAME)
		make -C $(LIB_DIR) fclean
		@echo "$(RED)=========== DONE ===========$(RESET)"
bonus: all
re: fclean all
