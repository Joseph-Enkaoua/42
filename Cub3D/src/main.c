/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henkaoua <henkaoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:36:37 by henkaoua          #+#    #+#             */
/*   Updated: 2023/02/07 16:37:06 by henkaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int ac, char **av)
{
	t_map	m;

	init(&m);
	check_input(ac, av, &m);
	m.win = mlx_new_window(m.mlx, WIN_W, WIN_H, "CUB3D");
	set_start_point(&m, m.start_y, m.start_x, m.start_direction);
	mlx_hook(m.win, 17, 1L << 19, &bye, NULL);
	mlx_hook(m.win, PRESS, 0, &ft_press, &m);
	mlx_hook(m.win, RELEASE, 0, &ft_released, &m);
	mlx_loop_hook(m.mlx, &check_move, &m);
	mlx_loop(m.mlx);
	return (0);
}
