/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f4_move_more.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henkaoua <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:30:33 by henkaoua          #+#    #+#             */
/*   Updated: 2021/12/17 19:30:53 by henkaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libx.h"

void	ft_exit(t_vars *vs)
{
	if (are_there_c(vs))
	{
		ft_free(vs->map);
		exit(0);
	}
}

void	go_left(t_vars *vs, int *c)
{
	vs->num++;
	vs->d_w = (vs->i) * 50;
	vs->d_h = (vs->j) * 50;
	set_image(vs, "./img/ground.xpm");
	vs->i = vs->i - 1;
	vs->d_w = vs->i * 50;
	if (vs->num % 2 > 0)
		set_image(vs, "./img/left1.xpm");
	else
		set_image(vs, "./img/left2.xpm");
	if (vs->map[vs->j][vs->i] == 'C')
		vs->map[vs->j][vs->i] = '0';
	(*c)++;
	vs->img = mlx_xpm_file_to_image(vs->mlx, "./img/border.xpm",
			&vs->img_width, &vs->img_height);
	mlx_put_image_to_window(vs->mlx, vs->win, vs->img, 200, 0);
	mlx_string_put(vs->mlx, vs->win, 200, 20, 0x000000, ft_itoa(*c));
}

void	ft_left(t_vars *vs, int *c)
{
	if (vs->map[vs->j][vs->i - 1] == '0' || vs->map[vs->j][vs->i - 1] == 'P'
			|| vs->map[vs->j][vs->i - 1] == 'C')
		go_left(vs, c);
	else if (vs->map[vs->j][vs->i - 1] == 'E')
		ft_exit(vs);
}

void	go_right(t_vars *vs, int *c)
{
	vs->num++;
	vs->d_w = (vs->i) * 50;
	vs->d_h = (vs->j) * 50;
	set_image(vs, "./img/ground.xpm");
	vs->i = vs->i + 1;
	vs->d_w = vs->i * 50;
	if (vs->num % 2 > 0)
		set_image(vs, "./img/right1.xpm");
	else
		set_image(vs, "./img/right2.xpm");
	if (vs->map[vs->j][vs->i] == 'C')
		vs->map[vs->j][vs->i] = '0';
	(*c)++;
	vs->img = mlx_xpm_file_to_image(vs->mlx, "./img/border.xpm",
			&vs->img_width, &vs->img_height);
	mlx_put_image_to_window(vs->mlx, vs->win, vs->img, 200, 0);
	mlx_string_put(vs->mlx, vs->win, 200, 20, 0x000000, ft_itoa(*c));
}

void	ft_right(t_vars *vs, int *c)
{
	if (vs->map[vs->j][vs->i + 1] == '0' || vs->map[vs->j][vs->i + 1] == 'P'
			|| vs->map[vs->j][vs->i + 1] == 'C')
		go_right(vs, c);
	else if (vs->map[vs->j][vs->i + 1] == 'E')
		ft_exit(vs);
}
