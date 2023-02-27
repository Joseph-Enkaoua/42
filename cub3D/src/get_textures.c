/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturbat <eturbat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:35:59 by eturbat           #+#    #+#             */
/*   Updated: 2023/02/13 13:36:05 by eturbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

//coverting the links to the images into mlx images
void	load_texture(t_map *m)
{
	m->no.img = mlx_xpm_file_to_image(m->mlx, m->no.path, &m->no.w, &m->no.h);
	if (!m->no.img)
		emergency_exit("Error: failed to allocate north texture", m, -1);
	m->no.addr = mlx_get_data_addr(m->no.img, &m->no.bits_per_pixel,
			&m->no.line_length, &m->no.endian);
	m->so.img = mlx_xpm_file_to_image(m->mlx, m->so.path, &m->so.w, &m->so.h);
	if (!m->so.img)
		emergency_exit("Error: failed to allocate south texture", m, -1);
	m->so.addr = mlx_get_data_addr(m->so.img, &m->so.bits_per_pixel,
			&m->so.line_length, &m->so.endian);
	m->we.img = mlx_xpm_file_to_image(m->mlx, m->we.path, &m->we.w, &m->we.h);
	if (!m->we.img)
		emergency_exit("Error: failed to allocate west texture", m, -1);
	m->we.addr = mlx_get_data_addr(m->we.img, &m->we.bits_per_pixel,
			&m->we.line_length, &m->we.endian);
	m->ea.img = mlx_xpm_file_to_image(m->mlx, m->ea.path, &m->ea.w, &m->ea.h);
	if (!m->ea.img)
		emergency_exit("Error: failed to allocate east texture", m, -1);
	m->ea.addr = mlx_get_data_addr(m->ea.img, &m->ea.bits_per_pixel,
			&m->ea.line_length, &m->ea.endian);
}

//allocating memory for the main mlx image
void	malloc_img(t_map *m)
{
	t_img		*img;

	img = malloc(sizeof(t_img));
	if (!img)
		emergency_exit("img malloc failed", m, -1);
	m->img = img;
	m->img->img = NULL;
}

//superfunction to the functions above
void	get_imgs_addr(t_map *m)
{
	load_texture(m);
	malloc_img(m);
}
