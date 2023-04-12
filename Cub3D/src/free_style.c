/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_style.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturbat <eturbat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:35:36 by eturbat           #+#    #+#             */
/*   Updated: 2023/02/26 14:34:11 by eturbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	**free2d(void **ar)
{
	int	i;

	i = -1;
	if (ar != NULL)
	{
		while (ar[++i] != NULL)
			free(ar[i]);
		free(ar);
	}
	return (NULL);
}

char	*free1d(void *str)
{
	if (str != NULL)
		free(str);
	return (NULL);
}

int	emergency_exit(char *str, t_map *m, int ret)
{
	printf("\033[0;31m%s\n\033[0m", str);
	m->we.path = free1d((void *)m->we.path);
	m->so.path = free1d((void *)m->so.path);
	m->no.path = free1d((void *)m->no.path);
	m->ea.path = free1d((void *)m->ea.path);
	m->map = free2d((void **)m->map);
	exit(ret);
}

int	bye(void)
{
	printf("\033[1;32mThanks for playing 🏁\n\033[0m");
	exit(0);
}
