/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henkaoua <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:55:23 by henkaoua          #+#    #+#             */
/*   Updated: 2021/12/17 18:52:06 by henkaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libx.h"

void	ft_free(char **map)
{
	int	i;

	i = -1;
	while (map[++i] != NULL)
		free(map[i]);
	free(map[i]);
	free(map);
}

int	if_valid(char c, int fd, char *buf)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P')
		return (1);
	else
	{
		close(fd);
		free(buf);
		printf("Error\ninvalid map!\n");
		exit(0);
	}
}

int	count_lines(char *s)
{
	int		num;
	int		i;
	int		fd;
	char	*buf;

	num = 1;
	i = -1;
	buf = malloc(1);
	fd = open(s, O_RDONLY);
	if (fd < 0)
	{
		perror("Error\n");
		exit(0);
	}
	while (num)
	{
		num = read(fd, buf, 1);
		if (*buf == '\n')
			i++;
		else
			if_valid(*buf, fd, buf);
	}
	close(fd);
	free(buf);
	return (i);
}

char	**ft_read(int lines, char *s)
{
	char	**map;
	int		fd;
	int		i;

	map = (char **)malloc((lines * sizeof(char *)) + 1);
	fd = open(s, O_RDONLY);
	if (fd < 0)
		exit(0);
	i = 0;
	while (i < lines)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	close(fd);
	check_map(map, lines);
	return (map);
}

int	main(int i, char **s)
{
	t_vars	vs;

	(void)i;
	vs.map = ft_read(count_lines(s[1]), s[1]);
	vs.d_w = 0;
	vs.d_h = 0;
	vs.num = 0;
	find_p(&vs);
	cnt_win_size(vs.map, &vs.win_h, &vs.win_w);
	vs.mlx = mlx_init();
	vs.win = mlx_new_window(vs.mlx, vs.win_w, vs.win_h, "z");
	set_img(&vs, vs.map);
	mlx_string_put(vs.mlx, vs.win, 70, 20, 0x000000, "num. of movements: ");
	mlx_key_hook(vs.win, ft_press, &vs);
	mlx_hook(vs.win, 17, 1L << 19, ft_close, &vs);
	mlx_loop(vs.mlx);
	ft_free(vs.map);
	return (0);
}
