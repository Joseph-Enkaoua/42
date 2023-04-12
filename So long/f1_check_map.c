/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f1_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henkaoua <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:18:33 by henkaoua          #+#    #+#             */
/*   Updated: 2021/12/14 16:10:58 by henkaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libx.h"

int	count_c(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	check_illegal_c(char **map)
{
	int	i;
	int	j;
	int	tab[255];

	j = -1;
	i = -1;
	while (++i < 255)
		tab[i] = 0;
	while (map[++j] != NULL)
	{
		i = -1;
		while (map[j][++i])
			tab[(int)map[j][i]] += 1;
	}
	if (tab[48] < 1 || tab[49] < 1 || tab[67] < 1
		|| tab[69] != 1 || tab[80] != 1)
		return (1);
	return (0);
}

int	check_borders(char **map, int lines)
{
	int	i;
	int	j;

	i = -1;
	while (map[0][++i])
		if (map[0][i] != '1')
			return (1);
	i = -1;
	while (map[lines - 1][++i])
		if (map[lines - 1][i] != '1')
			return (1);
	j = -1;
	while (++j < lines)
		if (map[j][0] != '1')
			return (1);
	j = -1;
	i--;
	while (++j < lines)
		if (map[j][i] != '1')
			return (1);
	return (0);
}

int	check_shape(char **map, int lines)
{
	int	i;

	if (lines > count_c(map[0]))
		return (1);
	i = 0;
	while (++i < lines)
	{
		if (count_c(map[i - 1]) != count_c(map[i]))
			return (1);
	}
	return (0);
}

void	check_map(char **map, int lines)
{
	if (check_illegal_c(map) || check_borders(map, lines)
		|| check_shape(map, lines))
	{
		ft_free(map);
		printf("Error\ninvalid map\n");
		exit(0);
	}
}
