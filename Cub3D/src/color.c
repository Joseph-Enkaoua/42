/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henkaoua <henkaoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:30:14 by henkaoua          #+#    #+#             */
/*   Updated: 2023/02/07 16:38:43 by henkaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

//return one int contains RGB colors
int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_r(int rgb)
{
	return ((rgb & (0xFF << 16)) >> 16);
}

int	get_g(int rgb)
{
	return ((rgb & (0xFF << 8)) >> 8);
}

int	get_b(int rgb)
{
	return (rgb & 0xFF);
}

int	gen_darker_color(int color)
{
	int	r;
	int	g;
	int	b;

	r = get_r(color) -1;
	if (r < 0)
		r = 0;
	g = get_g(color) -1;
	if (g < 0)
		g = 0;
	b = get_b(color) -1;
	if (b < 0)
		b = 0;
	color = create_trgb(0, r, g, b);
	return (color);
}
