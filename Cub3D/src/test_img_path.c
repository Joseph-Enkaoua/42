/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_img_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henkaoua <henkaoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 21:11:39 by henkaoua          #+#    #+#             */
/*   Updated: 2023/02/07 16:43:11 by henkaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	insert_line(char *new, t_map *m, char *old)
{
	if (!ft_strncmp(old, "EA", 2))
	{
		m->ea.path = new;
		return (1);
	}
	else if (!ft_strncmp(old, "NO", 2))
	{
		m->no.path = new;
		return (1);
	}
	else if (!ft_strncmp(old, "SO", 2))
	{
		m->so.path = new;
		return (1);
	}
	else if (!ft_strncmp(old, "WE", 2))
	{
		m->we.path = new;
		return (1);
	}
	else
	{
		free(new);
		return (0);
	}
}

//check if line is an img path
int	is_img_path(char *s, t_map *m, int i)
{
	char	*new;
	int		fd;

	if (ft_is_space(s[2]))
	{
		i += 2;
		while (ft_is_space(s[i]))
			i++;
		new = strdup(s + i);
		fd = open(new, O_RDONLY);
		if (fd < 0)
		{
			free(new);
			return (0);
		}
		close(fd);
		fd = insert_line(new, m, s);
		free(s);
		return (fd);
	}
	return (0);
}

//check if line is floor color
int	case_f(char *s, t_map *m, int i)
{
	char	**t;

	if (s[0] == 'F' && ft_is_space(s[1]))
	{
		i += 2;
		while (ft_is_space(s[i]))
			i++;
		if (s[i] == ',')
			emergency_exit("Error: invalid RGB details", m, -1);
		t = ft_split(s + i, ',');
		free(s);
		has_three_str(t, m);
		if (ft_atoi(t[0]) < 0 || ft_atoi(t[0]) > 255
			|| ft_atoi(t[1]) < 0 || ft_atoi(t[1]) > 255
			|| ft_atoi(t[2]) < 0 || ft_atoi(t[2]) > 255)
		{
			t = free2d((void **)t);
			return (0);
		}
		m->f = create_trgb(0, ft_atoi(t[0]), ft_atoi(t[1]), ft_atoi(t[2]));
		t = free2d((void **)t);
		return (1);
	}
	return (0);
}

//check if line is ceiling color
int	case_c(char *s, t_map *m, int i)
{
	char	**t;

	if (s[0] == 'C' && ft_is_space(s[1]))
	{
		i += 2;
		while (ft_is_space(s[i]))
			i++;
		if (s[i] == ',')
			emergency_exit("Error: invalid RGB details", m, -1);
		t = ft_split(s + i, ',');
		free(s);
		has_three_str(t, m);
		if (ft_atoi(t[0]) < 0 || ft_atoi(t[0]) > 255
			|| ft_atoi(t[1]) < 0 || ft_atoi(t[1]) > 255
			|| ft_atoi(t[2]) < 0 || ft_atoi(t[2]) > 255)
		{
			t = free2d((void **)t);
			return (0);
		}
		m->c = create_trgb(0, ft_atoi(t[0]), ft_atoi(t[1]), ft_atoi(t[2]));
		t = free2d((void **)t);
		return (1);
	}
	return (0);
}

//remove spaces before string
char	*remove_space(char *s)
{
	int		i;
	int		end;
	char	*new;

	i = 0;
	end = ft_strlen(s);
	while (ft_is_space(s[end - 1]))
		end--;
	while (ft_is_space(s[i]))
		i++;
	new = ft_substr(s, i, end - i);
	free(s);
	return (new);
}
