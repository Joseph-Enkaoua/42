/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anais <anais@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 10:40:19 by henkaoua          #+#    #+#             */
/*   Updated: 2023/01/14 00:49:29 by anais            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//check char validity for the map
int	check_c(char c)
{
	if (c == 'E' || c == 'S' || c == 'W' || c == 'N' || c == '1'
		|| c == '0' || c == ' ' || c == '\t')
		return (1);
	return (0);
}

char	*ft_strjoin_gnl(char *str, char c)
{
	char	*new;
	int		i;

	new = (char *)malloc((ft_strlen(str) + 2));
	if (new == NULL)
		return (0);
	i = -1;
	while (str[++i])
		new[i] = str[i];
	if (!(c == '\n' && str[0] != '\0'))
		new[i++] = c;
	new[i] = '\0';
	free(str);
	return (new);
}

char	*get_next_line(int fd)
{
	char	buf;
	char	*line;
	int		ret;
	int		i;

	line = ft_strdup("");
	ret = read(fd, &buf, 1);
	while (ret > 0)
	{
		line = ft_strjoin_gnl(line, buf);
		if (buf == '\n')
			break ;
		ret = read(fd, &buf, 1);
	}
	i = 0;
	while (line[i])
		i++;
	if (i == 0 || ret == -1)
	{
		free(line);
		line = NULL;
	}
	return (line);
}

char	*get_next_line_free(int fd, char *line)
{
	char	buf;
	int		ret;
	int		i;

	free(line);
	line = ft_strdup("");
	ret = read(fd, &buf, 1);
	while (ret > 0)
	{
		line = ft_strjoin_gnl(line, buf);
		if (buf == '\n')
			break ;
		ret = read(fd, &buf, 1);
	}
	i = 0;
	while (line[i])
		i++;
	if (i == 0 || ret == -1)
	{
		free(line);
		line = NULL;
	}
	return (line);
}
