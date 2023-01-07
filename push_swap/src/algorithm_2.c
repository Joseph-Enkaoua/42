/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henkaoua <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:29:00 by henkaoua          #+#    #+#             */
/*   Updated: 2022/02/13 03:51:28 by henkaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../push_swap.h"

int	find_min(t_stack *b)
{
	int	i;
	int	num;
	int	ret;

	num = 2147483647;
	ret = 0;
	i = -1;
	while (++i < b->size)
	{
		if (num > b->pile[i])
		{
			num = b->pile[i];
			ret = i;
		}
	}
	return (ret);
}

int	find_max(t_stack *b)
{
	int	i;
	int	num;
	int	ret;

	num = 0;
	ret = 0;
	i = -1;
	while (++i < b->size)
	{
		if (num < b->pile[i])
		{
			num = b->pile[i];
			ret = i;
		}
	}
	return (ret);
}

void	return_sorted_chunk(t_stack *a, t_stack *b)
{
	int	t;
	int	min;
	int	max;

	t = 0;
	while (b->size > 0)
	{
		min = find_min(b);
		max = find_max(b);
		if (max < min && max < b->size - min && max < b->size - max)
			max_up_won(a, b, &max, &t);
		else if (b->size - min < min && b->size - min < max
			&& b->size - min < b->size - max)
			min_down_won(a, b, &min);
		else if (b->size - max < min && b->size - max < max
			&& b->size - max < b->size - min)
			max_down_won(a, b, &max, &t);
		else
			min_up_won(a, b, &min);
	}
	while (--t >= 0)
		ra(a);
}

void	pick_chunk(t_stack *a, t_stack *b, t_mark *ar)
{
	while (is_it_here(a, ar->min, ar->max))
	{
		ar->i = a->size;
		while (--ar->i >= 0)
			if (a->pile[ar->i] >= ar->min && a->pile[ar->i] < ar->max)
				ar->hold_first = ar->i;
		while (++ar->i < a->size)
			if (a->pile[ar->i] >= ar->min && a->pile[ar->i] < ar->max)
				ar->hold_last = ar->i;
		if (ar->hold_first <= (a->size - ar->hold_last))
			while (ar->hold_first-- > 0)
				ra(a);
		else
			while (++(ar->hold_last) <= a->size)
				rra(a);
		pb(a, b);
	}
	compensation(a, ar, ar->min);
	return_sorted_chunk(a, b);
}

void	big_sort(t_stack *a, t_stack *b, int num)
{
	t_mark	ar;

	ar.min = 0;
	ar.max = num;
	ar.call = 0;
	ar.initial_size = a->size;
	ar.last_call = (a->size / num) - 1;
	while (ar.min < ar.initial_size)
	{
		pick_chunk(a, b, &ar);
		ar.min += num;
		ar.max += num;
		ar.call++;
	}
}
