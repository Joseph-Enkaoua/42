/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f2_fisrt_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henkaoua <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:21:42 by henkaoua          #+#    #+#             */
/*   Updated: 2021/12/17 19:38:33 by henkaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libx.h"

int	are_there_c(t_vars *vs)
{
	int	j;
	int	i;

	j = -1;
	while (vs->map[++j] != NULL)
	{
		i = -1;
		while (vs->map[j][++i])
			if (vs->map[j][i] == 'C')
				return (0);
	}
	return (1);
}

void	cnt_win_size(char **map, int *win_h, int *win_w)
{
	*win_h = 0;
	while (map[*win_h] != NULL)
		(*win_h)++;
	*win_w = 0;
	while (map[0][*win_w])
		(*win_w)++;
	*win_h = (*win_h) * 50;
	*win_w = (*win_w) * 50;
}

void	find_p(t_vars *vs)
{
	int	i;
	int	j;

	j = -1;
	while (vs->map[++j] != NULL)
	{
		i = -1;
		while (vs->map[j][++i])
		{
			if (vs->map[j][i] == 'P')
			{
				vs->j = j;
				vs->i = i;
			}
		}
	}
}

void	set_image(t_vars *vs, char *s)
{
	vs->relative_path = s;
	vs->img = mlx_xpm_file_to_image(vs->mlx, vs->relative_path,
			&vs->img_width, &vs->img_height);
	mlx_put_image_to_window(vs->mlx, vs->win, vs->img, vs->d_w, vs->d_h);
}

void	set_img(t_vars *vs, char **map)
{
	int	j;
	int	i;

	j = -1;
	vs->d_h = 0;
	while (map[++j])
	{
		i = -1;
		vs->d_w = 0;
		while (map[j][++i])
		{
			if (map[j][i] == '0')
				set_image(vs, "./img/ground.xpm");
			if (map[j][i] == '1')
				set_image(vs, "./img/border.xpm");
			if (map[j][i] == 'P')
				set_image(vs, "./img/right2.xpm");
			if (map[j][i] == 'E')
				set_image(vs, "./img/closed_exit.xpm");
			if (map[j][i] == 'C')
				set_image(vs, "./img/c.xpm");
			vs->d_w += 50;
		}
		vs->d_h += 50;
	}
}
