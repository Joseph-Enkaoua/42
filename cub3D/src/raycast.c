/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henkaoua <henkaoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:26:10 by henkaoua          #+#    #+#             */
/*   Updated: 2023/02/07 17:26:45 by henkaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

//Calculate length of ray from one x or y-side to next x or y-side
//Calculate step and initial sideDist
void	set_ray_len(t_rays *ray)
{
	ray->delta_dist_y = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_x = fabs(1 / ray->ray_dir_y);
	ray->hit = 0;
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (ray->pos_x - ray->map_x) * ray->delta_dist_y;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - ray->pos_x) * ray->delta_dist_y;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (ray->pos_y - ray->map_y) * ray->delta_dist_x;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - ray->pos_y) * ray->delta_dist_x;
	}
}

//Jump to next map square in x-direction OR in y-direction
//Check if ray has hit a wall
void	perform_dda(t_map *m)
{
	while (m->ray.hit == 0)
	{
		if (m->ray.side_dist_x < m->ray.side_dist_y)
		{
			m->ray.side_dist_x += m->ray.delta_dist_y;
			m->ray.map_x += m->ray.step_x;
			m->ray.side = 0;
		}
		else
		{
			m->ray.side_dist_y += m->ray.delta_dist_x;
			m->ray.map_y += m->ray.step_y;
			m->ray.side = 1;
		}
		if (m->map[m->ray.map_x][m->ray.map_y] == '1')
			m->ray.hit = 1;
	}
}

//Sets coordinates of texture image to use for wall
int	set_tex(t_map *m, t_img wall_img)
{
	if (m->ray.side == 0)
		m->ray.wall_x = m->ray.pos_y + m->ray.perp_wall_dist
			* m->ray.ray_dir_y;
	else
		m->ray.wall_x = m->ray.pos_x + m->ray.perp_wall_dist
			* m->ray.ray_dir_x;
	m->ray.wall_x -= floor((m->ray.wall_x));
	m->ray.x_tex = (int)(m->ray.wall_x * (double)wall_img.w);
	if ((m->ray.side == 0 && m->ray.ray_dir_x > 0)
		|| (m->ray.side == 1 && m->ray.ray_dir_y < 0))
		m->ray.x_tex = wall_img.w - m->ray.x_tex;
	m->ray.y_tex = 0;
	m->ray.y_tex_step = wall_img.h / (double)m->ray.line_height;
	if (m->ray.line_height > WIN_H)
		m->ray.y_tex = (m->ray.line_height - WIN_H)
			* m->ray.y_tex_step / 2;
	return (0);
}

//Draw texture on vertical wall line
int	draw_tex(t_map *m, t_img wall_img, int x)
{
	char	*dst;
	int		y_wall;
	int		color;

	set_tex(m, wall_img);
	y_wall = m->ray.draw_start;
	while (y_wall <= m->ray.draw_end)
	{
		dst = wall_img.addr + ((int)(m->ray.y_tex) % wall_img.h
				* wall_img.line_length + m->ray.x_tex % wall_img.w
				* (wall_img.bits_per_pixel / 8));
		color = *(unsigned int *)dst;
		my_mlx_pixel_put(m->img, x, y_wall, color);
		y_wall++;
		m->ray.y_tex += m->ray.y_tex_step;
	}
	return (0);
}

//Superfunction to calculate and draw the next image on the screen
void	draw_img(t_map *m)
{
	int	x;

	floor_and_ceiling(m);
	x = 0;
	while (x < WIN_W)
	{
		set_ray_pos(m, x);
		set_ray_len(&(m->ray));
		perform_dda(m);
		set_projection(&(m->ray));
		if (m->ray.side == 0 && m->ray.step_x == 1)
			draw_tex(m, m->so, x);
		if (m->ray.side == 0 && m->ray.step_x == -1)
			draw_tex(m, m->no, x);
		if (m->ray.side == 1 && m->ray.step_y == 1)
			draw_tex(m, m->ea, x);
		if (m->ray.side == 1 && m->ray.step_y == -1)
			draw_tex(m, m->we, x);
		x++;
	}
	mlx_put_image_to_window(m->mlx, m->win, m->img->img, 0, 0);
}
