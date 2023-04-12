/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henkaoua <henkaoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:34:36 by henkaoua          #+#    #+#             */
/*   Updated: 2023/02/26 14:50:17 by henkaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <math.h>
# include <time.h>
# include <sys/time.h>

# define STEP			0.1
# define ROTATE 		48
# define SKY_DARKNESS	4
# define WIN_W		 	1280
# define WIN_H 			640

# define W			13
# define S			1
# define D			2
# define A			0
# define RIGHT		124
# define LEFT		123
# define PRESS		2
# define RELEASE	3
# define ESC		53

typedef struct s_rays
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	int		x_tex;
	double	y_tex;
	double	y_tex_step;
	int		forward;
	int		backwards;
	int		left;
	int		right;
	int		rot_left;
	int		rot_right;
}	t_rays;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		w;
	int		h;
	char	*path;
}	t_img;

typedef struct s_map
{
	void	*mlx;
	void	*win;
	char	**map;
	int		f;
	int		c;
	int		start_x;
	int		start_y;
	char	start_direction;
	t_img	*img;
	t_img	no;
	t_img	so;
	t_img	we;
	t_img	ea;
	t_rays	ray;
}	t_map;

void	init(t_map *m);
void	check_input(int ac, char **av, t_map *m);
void	has_three_str(char **str, t_map *m);
int		is_img_path(char *s, t_map *m, int i);
void	get_imgs_addr(t_map *m);
char	*remove_space(char *s);
int		case_f(char *s, t_map *m, int i);
int		case_c(char *s, t_map *m, int i);
void	get_map(int fd, int lines, t_map *m);
void	rotate(t_map *m, double radians);
void	floor_and_ceiling(t_map *m);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
void	draw_img(t_map *m);
int		check_move(t_map *m);
int		create_trgb(int t, int r, int g, int b);
int		gen_darker_color(int color);
void	set_start_point(t_map *m, int l, int i, char c);
void	set_projection(t_rays *ray);
void	set_ray_pos(t_map *m, int x);
int		ft_press(int keycode, t_map *m);
int		ft_released(int keycode, t_map *m);
char	**free2d(void **ar);
int		emergency_exit(char *str, t_map *m, int ret);
int		bye(void);
#endif
