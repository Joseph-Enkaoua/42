/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henkaoua <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 03:27:51 by henkaoua          #+#    #+#             */
/*   Updated: 2022/02/13 03:38:29 by henkaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	compensation(t_stack *a, t_mark *ar, int last_a)
{
	int	i;

	i = a->size - 1;
	if (ar->call != ar->last_call)
		while (ar->call > 0 && a->pile[i] != last_a - 1)
			ra(a);
	else if (ar->call > 0)
		while (a->pile[i] != last_a - 1)
			rra(a);
}

void	min_up_won(t_stack *a, t_stack *b, int *min)
{
	while ((*min)-- > 0)
		rb(b);
	pa(a, b);
	ra(a);
}

void	max_up_won(t_stack *a, t_stack *b, int *max, int *t)
{
	while ((*max)-- > 0)
		rb(b);
	pa(a, b);
	(*t)++;
}

void	min_down_won(t_stack *a, t_stack *b, int *min)
{
	while (++(*min) <= b->size)
		rrb(b);
	pa(a, b);
	ra(a);
}

void	max_down_won(t_stack *a, t_stack *b, int *max, int *t)
{
	while (++(*max) <= b->size)
		rrb(b);
	pa(a, b);
	(*t)++;
}
