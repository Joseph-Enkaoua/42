/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henkaoua <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 10:40:19 by henkaoua          #+#    #+#             */
/*   Updated: 2021/12/09 17:02:47 by henkaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

int	ft_if_false(int fd, char **buffer, int num, int isempty)
{
	int	number;

	number = read(fd, *buffer, 0);
	if (fd < 0 || BUFFER_SIZE <= 0 || isempty == 1 || number < 0 || num < 0)
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
	static int	isempty;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	if (!ft_if_false(fd, &buffer, num, isempty))
		return (NULL);
	if (!story && num == 1)
		story = ft_strdup("");
	while (num > 0 && ft_strchr(story))
	{
		num = read(fd, buffer, BUFFER_SIZE);
		buffer[num] = '\0';
		story = ft_strjoin(story, buffer);
		isempty++;
	}
	story = ft_set_line(&story, &line, &isempty);
	free(buffer);
	buffer = NULL;
	return (line);
}
