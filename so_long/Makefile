NAME	= so_long

CC		= gcc
FLAGS	= -Wall -Werror -Wextra
MLX		= libmlx.a
SRC		= main.c f1_check_map.c f2_fisrt_img.c f3_start_moving.c f4_keep_moving.c f5_gnl.c f6_gnl_functions.c f7_itoa.c
OBJ		= $(SRC:.c=.o)

all: $(MLX) $(NAME)

$(MLX):
	make -C ./mlx

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
