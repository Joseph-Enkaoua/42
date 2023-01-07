/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f3_start_moving.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henkaoua <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:27:54 by henkaoua          #+#    #+#             */
/*   Updated: 2021/12/17 19:30:50 by henkaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libx.h"

void	go_down(t_vars *vs, int *c)
{
	vs->num++;
	vs->d_w = (vs->i) * 50;
	vs->d_h = (vs->j) * 50;
	set_image(vs, "./img/ground.xpm");
	vs->j = vs->j + 1;
	vs->d_h = vs->j * 50;
	if (vs->num % 2 > 0)
		set_image(vs, "./img/down1.xpm");
	else
		set_image(vs, "./img/down2.xpm");
	if (vs->map[vs->j][vs->i] == 'C')
		vs->map[vs->j][vs->i] = '0';
	(*c)++;
	vs->img = mlx_xpm_file_to_image(vs->mlx, "./img/border.xpm",
			&vs->img_width, &vs->img_height);
	mlx_put_image_to_window(vs->mlx, vs->win, vs->img, 200, 0);
	mlx_string_put(vs->mlx, vs->win, 200, 20, 0x000000, ft_itoa(*c));
}

void	ft_down(t_vars *vs, int *c)
{
	if (vs->map[vs->j + 1][vs->i] == '0' || vs->map[vs->j + 1][vs->i] == 'P'
			|| vs->map[vs->j + 1][vs->i] == 'C')
		go_down(vs, c);
	else if (vs->map[vs->j + 1][vs->i] == 'E')
		ft_exit(vs);
}

void	go_up(t_vars *vs, int *c)
{
	vs->num++;
	vs->d_w = (vs->i) * 50;
	vs->d_h = (vs->j) * 50;
	set_image(vs, "./img/ground.xpm");
	vs->j = vs->j - 1;
	vs->d_h = vs->j * 50;
	if (vs->num % 2 > 0)
		set_image(vs, "./img/up1.xpm");
	else
		set_image(vs, "./img/up2.xpm");
	if (vs->map[vs->j][vs->i] == 'C')
		vs->map[vs->j][vs->i] = '0';
	(*c)++;
	vs->img = mlx_xpm_file_to_image(vs->mlx, "./img/border.xpm",
			&vs->img_width, &vs->img_height);
	mlx_put_image_to_window(vs->mlx, vs->win, vs->img, 200, 0);
	mlx_string_put(vs->mlx, vs->win, 200, 20, 0x000000, ft_itoa(*c));
}

void	ft_up(t_vars *vs, int *c)
{
	if (vs->map[vs->j - 1][vs->i] == '0' || vs->map[vs->j - 1][vs->i] == 'P'
			|| vs->map[vs->j - 1][vs->i] == 'C')
		go_up(vs, c);
	else if (vs->map[vs->j - 1][vs->i] == 'E')
		ft_exit(vs);
}

int	ft_press(int keycode, t_vars *vs)
{
	static int	c;

	if (keycode == 13)
		ft_up(vs, &c);
	if (keycode == 1)
		ft_down(vs, &c);
	if (keycode == 2)
		ft_right(vs, &c);
	if (keycode == 0)
		ft_left(vs, &c);
	if (keycode == 53)
	{
		ft_free(vs->map);
		exit(0);
	}
	if (are_there_c(vs))
		ft_open_exit(vs);
	return (0);
}
