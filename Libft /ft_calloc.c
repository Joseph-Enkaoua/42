/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henkaoua <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:15:10 by henkaoua          #+#    #+#             */
/*   Updated: 2021/10/28 16:24:36 by henkaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(t_size count, t_size size)
{
	char	*vd;
    int		i;
	int		len;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	vd = (void *)malloc(count * size);
	if (!vd)
		return (0);
	i = -1;
	len = count * size;
	while (++i < len)
		vd[i] = 0;
	return ((void *)vd);
}
