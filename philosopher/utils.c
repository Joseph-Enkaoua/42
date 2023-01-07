/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fncs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henkaoua <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 21:06:50 by henkaoua          #+#    #+#             */
/*   Updated: 2022/03/30 16:53:11 by henkaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	size_t	num;
	int		i;

	num = 0;
	i = -1;
	while (str[++i] >= '0' && str[i] <= '9')
		num = num * 10 + (str[i] - 48);
	if (str[i] != '\0' || num > 2147483647)
		return (-1);
	return ((int)num);
}

int	freedom(pthread_t *t, t_individual *i, int ret)
{
	if (t)
		free(t);
	free(i);
	return (ret);
}

size_t	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	prepare(t_individual *i, t_rules *r)
{
	int	num;

	num = r->philos;
	while (num-- > 0)
	{
		if (num + 1 == r->philos)
			i[num].next = &i[0];
		else
			i[num].next = &i[num + 1];
		i[num].g = r;
		i[num].id = num + 1;
		i[num].num_eaten = 0;
		i[num].last_eat = get_time();
		pthread_mutex_init(&i[num].lock, NULL);
	}
	r->alive = 1;
}

int	init(int ag, char **av, t_rules *r)
{
	r->philos = ft_atoi(av[1]);
	r->to_die = ft_atoi(av[2]);
	r->to_eat = ft_atoi(av[3]);
	r->to_sleep = ft_atoi(av[4]);
	r->must_eat = 10000000;
	if (ag == 6)
		r->must_eat = ft_atoi(av[5]);
	if (!r->philos || !r->to_die || !r->to_eat || !r->to_sleep || !r->must_eat)
		return (0);
	return (1);
}
