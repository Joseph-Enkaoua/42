NAME 		=	cub3D
LIBFT 		= 	libft.a
LIB_DIR		=	libft/
MLX			=	libmlx.a
MLX_DIR		=	mlx/
OBJS 		= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
OBJ_DIR		=	obj/
LFLAGS		= -I include/
CFLAGS		= -Wall -Wextra -Werror
DEBUGGING	= -g -O0
FSANITIZE	= -fsanitize=address
CC			= gcc
RM			= rm -rf
AR			= ar rc
SRCS_DIR	=	src/
SRCS		=	main.c			\
				init.c			\
				parse_input.c	\
				get_textures.c	\
				test_img_path.c	\
				parse_map.c		\
				hooks.c			\
				move.c			\
				raycast.c		\
				raycast_tools.c	\
				color.c			\
				free_style.c

all:  $(MLX) $(NAME)

$(MLX):
	make -C ./mlx

$(OBJ_DIR)%.o : $(SRCS_DIR)%.c
		@mkdir -p $(OBJ_DIR)
		$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(OBJS)
		make -C $(LIB_DIR)
		$(CC) $(CFLAGS) $(OBJS) $(LIB_DIR)$(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
		clear

clean:
		$(RM) $(OBJ_DIR)
		$(RM) $(OBJS)
		make -C $(LIB_DIR) clean
		make -C $(MLX_DIR) clean

fclean: clean
		$(RM) $(NAME)
		make -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean re fclean
