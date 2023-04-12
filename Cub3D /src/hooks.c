/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturbat <eturbat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:59:12 by henkaoua          #+#    #+#             */
/*   Updated: 2023/02/17 11:49:37 by eturbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_press(int keycode, t_map *m)
{
	if (keycode == ESC)
		bye();
	if (keycode == W)
		m->ray.forward = 1;
	if (keycode == S)
		m->ray.backwards = 1;
	if (keycode == D)
		m->ray.right = 1;
	if (keycode == A)
		m->ray.left = 1;
	if (keycode == LEFT)
		m->ray.rot_left = 1;
	if (keycode == RIGHT)
		m->ray.rot_right = 1;
	return (keycode);
}

int	ft_released(int keycode, t_map *m)
{
	(void)m;
	if (keycode == W)
		m->ray.forward = 0;
	if (keycode == S)
		m->ray.backwards = 0;
	if (keycode == D)
		m->ray.right = 0;
	if (keycode == A)
		m->ray.left = 0;
	if (keycode == LEFT)
		m->ray.rot_left = 0;
	if (keycode == RIGHT)
		m->ray.rot_right = 0;
	return (keycode);
}
