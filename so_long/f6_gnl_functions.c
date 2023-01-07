/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f6_gnl_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henkaoua <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:37:57 by henkaoua          #+#    #+#             */
/*   Updated: 2021/12/14 13:38:16 by henkaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libx.h"

char	*ft_set_line(char **story, char **line)
{
	char	*new_story;
	int		i;

	i = 0;
	while ((*story)[i] != '\n' && (*story)[i])
		i++;
	if ((*story)[i] == '\n')
	{
		i++;
		*line = ft_substr(*story, 0, i);
	}
	else if ((*story)[i] == '\0')
		*line = ft_substr(*story, 0, i);
	new_story = ft_strdup(*story + i);
	if (i == 0)
	{
		free(new_story);
		free(*line);
		*line = NULL;
	}
	free(*story);
	return (new_story);
}

int	ft_strchr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_close(t_vars *vs)
{
	ft_free(vs->map);
	exit(0);
	return (0);
}
