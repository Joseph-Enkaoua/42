/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henkaoua <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 21:13:22 by henkaoua          #+#    #+#             */
/*   Updated: 2022/03/31 14:51:12 by henkaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_pt(pthread_t *t, t_rules *r, t_individual *i)
{
	int	num;

	num = r->philos;
	while (num-- > 0)
		if (pthread_create(&t[num], NULL, &routine, (void *)&i[num]) != 0)
			return (freedom(t, i, 0));
	num = r->philos;
	while (--num >= 0)
		if (pthread_join(t[num], NULL) != 0)
			return (freedom(NULL, i, 2));
	return (1);
}

int	one_and_only(pthread_t *t, t_individual *i, int to_die)
{
	usleep(to_die * 1000);
	printf("%ld 1 died\n", get_time());
	return (freedom(t, i, 0));
}

int	main(int ag, char **av)
{
	t_rules			r;
	t_individual	*i;
	pthread_t		*t;
	int				num;

	if (ag < 5 || ag > 6)
		return (write(2, "Arguments error\n", 16));
	if (!init(ag, av, &r))
		return (write(2, "Arguments error\n", 16));
	t = (pthread_t *)malloc(sizeof(pthread_t) * r.philos);
	i = (t_individual *)malloc(sizeof(t_individual) * r.philos);
	prepare(i, &r);
	if (r.philos == 1)
		return (one_and_only(t, i, r.to_die));
	pthread_mutex_init(&r.lock, NULL);
	num = create_pt(t, &r, i);
	if (!num)
		return (write(2, "Failed to create thread\n", 24));
	if (num == 2)
		return (write(2, "Failed to join thread\n", 22));
	num = r.philos;
	while (num-- > 0)
		pthread_mutex_destroy(&i[num].lock);
	pthread_mutex_destroy(&r.lock);
	return (freedom(t, i, 0));
}
