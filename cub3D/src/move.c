/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henkaoua <henkaoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:40:12 by henkaoua          #+#    #+#             */
/*   Updated: 2023/02/07 16:40:46 by henkaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

//Moves player position in map
int	move_player(t_map *m, double x, double y)
{
	if (m->map[(int)(m->ray.pos_x + x * STEP)]
		[(int)(m->ray.pos_y)] == '0')
	{
		draw_img(m);
		m->ray.pos_x += x * (STEP - 0.01);
	}
	if (m->map[(int)(m->ray.pos_x)][(int)
		(m->ray.pos_y + y * STEP)] == '0')
	{
		draw_img(m);
		m->ray.pos_y += y * (STEP - 0.01);
	}
	return (0);
}

int	check_move(t_map *m)
{
	if (m->ray.forward)
		move_player(m, m->ray.dir_x, m->ray.dir_y);
	if (m->ray.backwards)
		move_player(m, -m->ray.dir_x, -m->ray.dir_y);
	if (m->ray.left)
		move_player(m, -m->ray.plane_x, -m->ray.plane_y);
	if (m->ray.right)
		move_player(m, m->ray.plane_x, m->ray.plane_y);
	if (m->ray.rot_right)
		rotate(m, -(M_PI / ROTATE));
	if (m->ray.rot_left)
		rotate(m, (M_PI / ROTATE));
	return (1);
}
