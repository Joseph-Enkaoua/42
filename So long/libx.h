/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libx.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henkaoua <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:39:25 by henkaoua          #+#    #+#             */
/*   Updated: 2021/12/17 19:31:52 by henkaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBX_H
# define LIBX_H
# include <stdio.h>
# include "mlx/mlx.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_vars {
	void	*mlx;
	void	*win;
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;
	int		win_w;
	int		win_h;
	int		d_w;
	int		d_h;
	char	**map;
	int		j;
	int		i;
	int		num;
}	t_vars;

char	*get_next_line(int fd);
char	*ft_set_line(char **story, char **line);
char	*ft_strdup(char *s);
char	*ft_substr(char *s, int start, int len);
int		ft_len(char *str);
void	check_map(char **map, int lines);
void	ft_free(char **map);
char	**ft_read(int lines, char *s);
int		count_lines(char *s);
int		ft_strchr(char *str);
void	cnt_win_size(char **map, int *win_h, int *win_w);
void	set_image(t_vars *vs, char *s);
void	set_img(t_vars *vs, char **map);
void	find_p(t_vars *vs);
void	ft_exit(t_vars *vs);
void	go_up(t_vars *vs, int *c);
void	ft_up(t_vars *vs, int *c);
void	go_right(t_vars *vs, int *c);
void	ft_right(t_vars *vs, int *c);
void	go_left(t_vars *vs, int *c);
void	ft_left(t_vars *vs, int *c);
void	go_down(t_vars *vs, int *c);
void	ft_down(t_vars *vs, int *c);
int		ft_press(int keycode, t_vars *vs);
int		ft_close(t_vars *vs);
char	*ft_itoa(int n);
int		are_there_c(t_vars *vs);
void	ft_open_exit(t_vars *vs);
#endif
