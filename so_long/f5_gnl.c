/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f5_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henkaoua <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:36:00 by henkaoua          #+#    #+#             */
/*   Updated: 2021/12/14 13:36:22 by henkaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libx.h"

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

char	*ft_substr(char *s, int start, int len)
{
	char	*str;
	int		i;
	int		l;

	i = 0;
	l = 0;
	while (s[l])
		l++;
	l = start;
	while (s[l++] && len-- > 0)
		i++;
	str = (char *)malloc((i + 1));
	if (str == NULL)
		return (0);
	l = 0;
	while (i-- > 0)
		str[l++] = s[start++];
	str[l] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		k;

	k = -1;
	i = -1;
	str = (char *)malloc((ft_len(s1) + ft_len(s2) + 1));
	if (str == NULL)
		return (0);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++k])
		str[i++] = s2[k];
	str[i] = '\0';
	free(s1);
	return (str);
}

int	ft_if_false(int fd, char **buffer, int num)
{
	int	number;

	number = read(fd, *buffer, 0);
	if (fd < 0 || number < 0 || num < 0)
	{
		free(*buffer);
		*buffer = NULL;
		return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*story = NULL;
	static int	num = 1;

	buffer = (char *)malloc(2);
	if (!buffer)
		return (0);
	if (!ft_if_false(fd, &buffer, num))
		return (NULL);
	if (!story && num == 1)
		story = ft_strdup("");
	while (num > 0 && ft_strchr(story))
	{
		num = read(fd, buffer, 1);
		buffer[num] = '\0';
		if (*buffer == '\n')
			break ;
		story = ft_strjoin(story, buffer);
	}
	story = ft_set_line(&story, &line);
	free(buffer);
	buffer = NULL;
	return (line);
}
