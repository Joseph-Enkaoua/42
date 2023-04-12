/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henkaoua <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 09:49:34 by henkaoua          #+#    #+#             */
/*   Updated: 2022/02/13 03:56:19 by henkaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	mini_f(char c, int *g, int *i)
{
	if (c == 45)
	{
		*g = -1;
		(*i)++;
	}
}

long int	ft_atoi(const char *str)
{
	long int	num;
	int			i;
	int			g;

	num = 0;
	i = 0;
	g = 1;
	while (str[i] == 32 || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if ((!(str[i] > 47 && str[i] < 58) && str[i] != 45)
		|| (str[i] == 45
			&& !(str[i + 1] > 47 && str[i + 1] < 58)))
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	mini_f(str[i], &g, &i);
	while (str[i] > 47 && str[i] < 58)
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	num = num * g;
	return (num);
}
