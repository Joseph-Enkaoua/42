/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henkaoua <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 09:51:48 by henkaoua          #+#    #+#             */
/*   Updated: 2022/02/09 14:29:44 by henkaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	buzz_the_tower(t_stack *a)
{
	int	i;
	int	goose;
	int	maverick;

	i = -1;
	goose = 0;
	maverick = 0;
	while (a->pile[++i] < a->size)
	{
		if (a->pile[i] > goose)
		{
			maverick = i;
			goose = a->pile[i];
		}
	}
	return (maverick);
}

int	walk_in_the_park(t_stack *a)
{
	int	i;
	int	jester;
	int	iceman;

	i = -1;
	jester = 2147483647;
	while (++i < a->size)
	{
		if (a->pile[i] < jester)
		{
			iceman = i;
			jester = a->pile[i];
		}
	}
	return (iceman);
}

t_stack	*triple_sort(t_stack *a)
{
	if (a->pile[0] > a->pile[1])
	{
		if (a->pile[2] > a->pile[0])
			sa(a);
		else
			ra(a);
	}
	if (a->pile[1] > a->pile[2])
		rra(a);
	if (a->pile[0] > a->pile[1])
		sa(a);
	return (a);
}

void	small_sort(t_stack *a, t_stack *b)
{
	int	i;

	while (a->size > 3)
	{
		i = walk_in_the_park(a);
		if (i < 3)
			while (--i >= 0)
				ra(a);
		else
			while (++i <= a->size)
				rra(a);
		pb(a, b);
	}
	triple_sort(a);
	pa(a, b);
	pa(a, b);
}
