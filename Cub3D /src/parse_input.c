/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturbat <eturbat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:36:35 by eturbat           #+#    #+#             */
/*   Updated: 2023/02/13 13:36:41 by eturbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

//return map lines since first non \n char
int	count_map_lines(int fd)
{
	int		i;
	char	*line;

	i = 0;
	while (i < 6)
	{
		line = get_next_line(fd);
		if (line[0] != '\n')
			i++;
		free(line);
	}
	i = 0;
	line = get_next_line(fd);
	while (line[0] == '\n')
		line = get_next_line_free(fd, line);
	while (line != NULL)
	{
		line = get_next_line_free(fd, line);
		i++;
	}
	close(fd);
	return (i);
}

//checks if 2D array contains exactly 3 valid strings
void	has_three_str(char **str, t_map *m)
{
	int	i;

	i = 0;
	if (str == NULL)
		emergency_exit("Error: RGB line is corrupted\n", m, -1);
	while (str[i] != NULL)
		i++;
	if (i != 3)
		emergency_exit("Error: RGB line is corrupted", m, -1);
}

//check that all elemets are filled
void	is_everyone_here(t_map *m)
{
	if (m->c == 0 || m->f == 0 || m->ea.path == NULL || m->no.path == NULL
		|| m->so.path == NULL || m->we.path == NULL)
		emergency_exit("Error: file missing required arguments", m, -1);
}

//test that there's only a valid ".cub" file
int	check_argv(int ac, char **av, t_map *m)
{
	int	i;
	int	fd;
	int	lines;

	if (ac != 2)
		emergency_exit("Error: incorrect arguments inserted\n", m, -1);
	i = 0;
	while (av[1][i])
		i++;
	fd = open(av[1], O_RDONLY);
	if (av[1][--i] != 'b' || av[1][--i] != 'u' || av[1][--i] != 'c'
		|| av[1][--i] != '.' || fd < 0)
		emergency_exit("Error: '.cub' file path is not correct", m, -1);
	lines = count_map_lines(fd);
	return (lines);
}

//super function of all validity tests
void	check_input(int ac, char **av, t_map *m)
{
	int		fd;
	int		i;
	int		lines;
	char	*ln;

	lines = check_argv(ac, av, m);
	if (lines < 3)
		emergency_exit("Error: invalid map", m, -1);
	fd = open(av[1], O_RDONLY);
	i = 0;
	while (++i < 7)
	{
		ln = get_next_line(fd);
		while (ln[0] == '\n')
			ln = get_next_line_free(fd, ln);
		ln = remove_space(ln);
		if (!is_img_path(ln, m, 0) && !case_f(ln, m, 0) && !case_c(ln, m, 0))
			emergency_exit("Error: path to xpm files \
/ RGB specs invalid", m, -1);
	}
	is_everyone_here(m);
	get_imgs_addr(m);
	get_map(fd, lines, m);
	close(fd);
}
