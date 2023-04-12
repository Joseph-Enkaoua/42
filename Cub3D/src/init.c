/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturbat <eturbat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:36:21 by eturbat           #+#    #+#             */
/*   Updated: 2023/02/26 14:33:56 by eturbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init(t_map *m)
{
	m->mlx = mlx_init();
	m->ea.path = NULL;
	m->no.path = NULL;
	m->so.path = NULL;
	m->we.path = NULL;
	m->c = 0;
	m->f = 0;
	m->map = NULL;
	m->ray.dir_x = -1;
	m->ray.dir_y = 0;
	m->ray.plane_x = 0;
	m->ray.plane_y = 0.66;
	m->ray.forward = 0;
	m->ray.backwards = 0;
	m->ray.left = 0;
	m->ray.right = 0;
	m->ray.rot_left = 0;
	m->ray.rot_right = 0;
}

//setting up start location
void	set_start_point(t_map *m, int l, int i, char c)
{
	double	radians;

	m->img->img = mlx_new_image(m->mlx, WIN_W, WIN_H);
	m->img->addr = mlx_get_data_addr(m->img->img,
			&m->img->bits_per_pixel, &m->img->line_length, &m->img->endian);
	m->ray.pos_y = i + 0.5;
	m->ray.pos_x = l + 0.5;
	m->map[l][i] = '0';
	radians = 0;
	if (c == 'E')
		radians = 1.5 * M_PI;
	else if (c == 'S')
		radians = M_PI;
	else if (c == 'W')
		radians = M_PI / 2;
	rotate(m, radians);
}
