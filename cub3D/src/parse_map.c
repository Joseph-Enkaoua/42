/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturbat <eturbat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:36:48 by eturbat           #+#    #+#             */
/*   Updated: 2023/02/13 13:36:54 by eturbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

//making sure that every non '1' char is surrounded by chars
void	look_around(t_map *m, int i, int k)
{
	if (i == 0 || m->map[i + 1] == NULL || !(check_c(m->map[i][k - 1])
		&& !ft_is_space(m->map[i][k - 1]) && check_c(m->map[i][k + 1])
		&& !ft_is_space(m->map[i][k + 1]) && check_c(m->map[i - 1][k])
		&& !ft_is_space(m->map[i - 1][k]) && check_c(m->map[i + 1][k])
		&& !ft_is_space(m->map[i + 1][k])))
		emergency_exit("Error: map not closed or has wrong character", m, -1);
}

//test that there's exacly one starting position on map
void	double_start(t_map *m)
{
	int		i;
	int		l;
	int		start_point;
	char	c;

	l = -1;
	start_point = 0;
	while (m->map[++l])
	{
		i = -1;
		while (m->map[l][++i])
		{
			c = m->map[l][i];
			if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
			{
				m->start_y = l;
				m->start_x = i;
				m->start_direction = c;
				start_point++;
			}
		}
	}
	if (start_point != 1)
		emergency_exit("Error: map doesn't have 1 starting position", m, -1);
}

//test the map
void	check_map(t_map *m)
{
	int	i;
	int	k;

	i = -1;
	while (m->map[++i])
	{
		k = -1;
		while (m->map[i][++k])
		{
			if (check_c(m->map[i][k]) || m->map[i][k] == '\n')
			{
				if (m->map[i][k] != '1' && !ft_is_space(m->map[i][k])
					&& m->map[i][k] != '\n')
					look_around(m, i, k);
			}
			else
				emergency_exit("Error: invalid map", m, -1);
		}
	}
	double_start(m);
}

//get the map
void	get_map(int fd, int lines, t_map *m)
{
	int		i;
	char	*str;

	m->map = (char **)malloc((lines * sizeof(char *)) + 1);
	str = get_next_line(fd);
	while (str[0] == '\n')
		str = get_next_line_free(fd, str);
	i = -1;
	while (++i < lines)
	{
		m->map[i] = str;
		str = get_next_line(fd);
	}
	free(str);
	m->map[i] = NULL;
	check_map(m);
}
