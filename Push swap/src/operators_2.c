/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henkaoua <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:22:26 by henkaoua          #+#    #+#             */
/*   Updated: 2022/02/09 15:44:54 by henkaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack *a)
{
	int	i;
	int	temp;

	temp = a->pile[0];
	i = 0;
	while (++i < a->size)
		a->pile[i - 1] = a->pile[i];
	a->pile[i - 1] = temp;
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	int	i;
	int	temp;

	temp = b->pile[0];
	i = 0;
	while (++i < b->size)
		b->pile[i - 1] = b->pile[i];
	b->pile[i - 1] = temp;
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	int	i;
	int	temp;

	temp = a->pile[0];
	i = 0;
	while (++i < a->size)
		a->pile[i - 1] = a->pile[i];
	a->pile[i - 1] = temp;
	temp = b->pile[0];
	i = 0;
	while (++i < b->size)
		b->pile[i - 1] = b->pile[i];
	b->pile[i - 1] = temp;
	write(1, "rr\n", 3);
}

void	rra(t_stack *a)
{
	int	i;
	int	temp;

	temp = a->pile[a->size - 1];
	i = a->size;
	while (--i)
		a->pile[i] = a->pile[i - 1];
	a->pile[0] = temp;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	int	i;
	int	temp;

	temp = b->pile[b->size - 1];
	i = b->size;
	while (--i)
		b->pile[i] = b->pile[i - 1];
	b->pile[0] = temp;
	write(1, "rrb\n", 4);
}
