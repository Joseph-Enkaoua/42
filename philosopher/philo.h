/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henkaoua <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:31:43 by henkaoua          #+#    #+#             */
/*   Updated: 2022/03/30 15:35:22 by henkaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_rules {
	int				philos;
	unsigned int	to_die;
	unsigned int	to_eat;
	int				to_sleep;
	int				must_eat;
	int				alive;
	pthread_mutex_t	lock;
}	t_rules;
typedef struct s_individual {
	size_t				last_eat;
	int					num_eaten;
	int					id;
	pthread_mutex_t		lock;
	struct s_individual	*next;
	t_rules				*g;
	int					fed_up;
}	t_individual;
int		init(int ag, char **av, t_rules *r);
void	prepare(t_individual *i, t_rules *r);
int		take_fork(t_individual *i);
void	*routine(void *arg);
int		monitor(t_individual *i);
int		freedom(pthread_t *t, t_individual *i, int ret);
size_t	get_time(void);
#endif
