/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henkaoua <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 10:36:16 by henkaoua          #+#    #+#             */
/*   Updated: 2021/10/26 11:53:53 by henkaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	int		i;
	int		n;
	int		k;

	if (!s1 || !s2)
		return (NULL);
	k = 0;
	n = (int)ft_strlen(s1) + (int)ft_strlen(s2);
	str = (char *)malloc((n + 1) * sizeof(char));
	if (str == NULL)
		return (0);
	i = -1;
	while (s1[++i])
	{
		str[k] = s1[i];
		k++;
	}
	i = -1;
	while (s2[++i])
		str[k++] = s2[i];
	str[k] = '\0';
	return (str);
}
