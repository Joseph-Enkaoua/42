/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henkaoua <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 14:45:01 by henkaoua          #+#    #+#             */
/*   Updated: 2022/02/05 19:34:43 by henkaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack *a)
{
	int	temp;

	if (a->size > 1)
	{
		temp = a->pile[0];
		a->pile[0] = a->pile[1];
		a->pile[1] = temp;
		write(1, "sa\n", 3);
	}
}

void	sb(t_stack *b)
{
	int	temp;

	if (b->size > 1)
	{
		temp = b->pile[0];
		b->pile[0] = b->pile[1];
		b->pile[1] = temp;
		write(1, "sb\n", 1);
	}
}

void	ss(t_stack *a, t_stack *b)
{
	int	temp;

	if (a->size > 1 && b->size > 1)
	{
		temp = a->pile[0];
		a->pile[0] = a->pile[1];
		a->pile[1] = temp;
		temp = b->pile[0];
		b->pile[0] = b->pile[1];
		b->pile[1] = temp;
		write(1, "ss\n", 3);
	}
}

void	pa(t_stack *a, t_stack *b)
{
	int	i;
	int	*new_pile;

	if (b->size > 0)
	{
		new_pile = (int *)malloc((a->size + 1) * sizeof(int));
		new_pile[0] = b->pile[0];
		i = -1;
		while (++i < a->size)
			new_pile[i + 1] = a->pile[i];
		free(a->pile);
		a->pile = new_pile;
		new_pile = (int *)malloc((b->size - 1) * sizeof(int));
		i = 0;
		while (++i < b->size)
			new_pile[i - 1] = b->pile[i];
		free(b->pile);
		b->pile = new_pile;
		a->size = a->size + 1;
		b->size = b->size - 1;
		write(1, "pa\n", 3);
	}
}

void	pb(t_stack *a, t_stack *b)
{
	int	i;
	int	*new_pile;

	if (a->size > 0)
	{
		new_pile = (int *)malloc((b->size + 1) * sizeof(int));
		new_pile[0] = a->pile[0];
		i = -1;
		while (++i < b->size)
			new_pile[i + 1] = b->pile[i];
		free(b->pile);
		b->pile = new_pile;
		new_pile = (int *)malloc((a->size - 1) * sizeof(int));
		i = 0;
		while (++i < a->size)
			new_pile[i - 1] = a->pile[i];
		free(a->pile);
		a->pile = new_pile;
		a->size = a->size - 1;
		b->size = b->size + 1;
		write(1, "pb\n", 3);
	}
}
