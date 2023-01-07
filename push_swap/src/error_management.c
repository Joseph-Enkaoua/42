/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henkaoua <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:46:30 by henkaoua          #+#    #+#             */
/*   Updated: 2022/02/13 02:44:06 by henkaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*malloc_it(char *str)
{
	char	*ret;
	int		i;

	i = 0;
	while (str[i])
		i++;
	ret = malloc(i + 1);
	i = -1;
	while (str[++i])
		ret[i] = str[i];
	ret[i] = '\0';
	return (ret);
}

void	ft_error(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str[i]);
	free(str);
	write(2, "Error\n", 6);
	exit(0);
}

void	check_int_array(long int *arr, char **str)
{
	int	i;
	int	d;
	int	e;

	i = -1;
	e = 1;
	while (str[++i])
	{
		if (arr[i] > 2147483647 || arr[i] < -2147483648)
			e = 0;
		d = -1;
		while (++d < i)
		{
			if (arr[d] == arr[i])
				e = 0;
		}
	}
	if (e == 0)
	{
		free((void *)arr);
		ft_error(str);
	}
}

int	*convert_and_free(long int *lon, int d, char **str)
{
	int	*arr;

	arr = (int *)malloc(sizeof(int) * d);
	while (--d >= 0)
		arr[d] = (int)lon[d];
	while (str[++d])
		free(str[d]);
	free(str);
	free(lon);
	return (arr);
}

int	*check_validity(char **str, t_stack *a, t_stack *b)
{
	int			i;
	int			d;
	int			*ret;
	long int	*lon;

	d = -1;
	while (str[++d])
	{
		i = -1;
		while (str[d][++i])
			if ((!(str[d][i] > 47 && str[d][i] < 58) && str[d][i] != 45)
					|| (str[d][i] == 45
						&& !(str[d][i + 1] > 47 && str[d][i + 1] < 58)))
				ft_error(str);
	}
	lon = (long int *)malloc(sizeof(long int) * d);
	i = -1;
	while (str[++i])
		lon[i] = ft_atoi(str[i]);
	a->size = i;
	b->size = 0;
	check_int_array(lon, str);
	ret = convert_and_free(lon, d, str);
	return (ret);
}
