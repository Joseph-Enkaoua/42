/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henkaoua <henkaoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:29:11 by henkaoua          #+#    #+#             */
/*   Updated: 2023/02/07 16:41:31 by henkaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

//Calculate x-coordinate in camera space
//Calculate ray position and direction
//Save which box of the map we're in
void	set_ray_pos(t_map *m, int x)
{
	m->ray.camera_x = 2 * x / (double)WIN_W - 1;
	m->ray.ray_dir_x = m->ray.dir_x + m->ray.plane_x * m->ray.camera_x;
	m->ray.ray_dir_y = m->ray.dir_y + m->ray.plane_y * m->ray.camera_x;
	m->ray.map_x = (int)m->ray.pos_x;
	m->ray.map_y = (int)m->ray.pos_y;
}

//Calculate distance projected on camera direction
//Calculate height of line to draw on screen
//Calculate lowest and highest pixel to fill in current stripe
void	set_projection(t_rays *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - ray->pos_x
				+ (1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - ray->pos_y
				+ (1 - ray->step_y) / 2) / ray->ray_dir_y;
	ray->line_height = (int)(WIN_H / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + WIN_H / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WIN_H / 2;
	if (ray->draw_end >= WIN_H)
		ray->draw_end = WIN_H - 1;
}

void	rotate(t_map *m, double radians)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = m->ray.dir_x;
	m->ray.dir_x = m->ray.dir_x * cos(radians)
		- m->ray.dir_y * sin(radians);
	m->ray.dir_y = old_dir_x * sin(radians) + m->ray.dir_y * cos(radians);
	old_plane_x = m->ray.plane_x;
	m->ray.plane_x = m->ray.plane_x * cos(radians)
		- m->ray.plane_y * sin(radians);
	m->ray.plane_y = old_plane_x * sin(radians)
		+ m->ray.plane_y * cos(radians);
	draw_img(m);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	floor_and_ceiling(t_map *m)
{
	int	l;
	int	i;
	int	color;

	l = -1;
	color = m->c;
	while (++l < WIN_H)
	{
		i = -1;
		if (l % SKY_DARKNESS == 0)
			color = gen_darker_color(color);
		while (++i < WIN_W)
		{
			if (l < WIN_H / 2)
				my_mlx_pixel_put(m->img, i, l, color);
			else
				my_mlx_pixel_put(m->img, i, l, m->f);
		}	
	}
}
