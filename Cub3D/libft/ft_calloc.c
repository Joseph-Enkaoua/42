/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anais <anais@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:15:10 by henkaoua          #+#    #+#             */
/*   Updated: 2023/01/09 22:26:39 by anais            ###   ########.fr       */
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
