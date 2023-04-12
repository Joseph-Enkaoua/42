/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henkaoua <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:33:34 by henkaoua          #+#    #+#             */
/*   Updated: 2022/03/08 15:03:58 by henkaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *s)
{
	char	*pst;
	int		i;

	i = 0;
	while (s[i])
		i++;
	pst = (char *)malloc(i + 1);
	if (pst == NULL)
		return (0);
	i = -1;
	while (s[++i])
		pst[i] = s[i];
	pst[i] = '\0';
	return (pst);
}

char	*ft_substr(char *s, int len)
{
	char	*str;
	int		i;
	int		l;

	i = 0;
	l = 0;
	while (s[l++] && len-- > 0)
		i++;
	str = (char *)malloc((i + 1));
	if (str == NULL)
		return (0);
	l = 0;
	while (i-- > 0)
	{
		str[l] = s[l];
		l++;
	}
	str[l] = '\0';
	return (str);
}

char	*ft_set_line(char **story, char **line, int *isempty)
{
	char	*new_story;
	int		i;

	i = 0;
	while ((*story)[i] != '\n' && (*story)[i])
		i++;
	if ((*story)[i] == '\n')
	{
		i++;
		*line = ft_substr(*story, i);
		*isempty += 1;
	}
	else if ((*story)[i] == '\0')
		*line = ft_substr(*story, i);
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
