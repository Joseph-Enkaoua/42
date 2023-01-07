/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henkaoua <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:59:03 by henkaoua          #+#    #+#             */
/*   Updated: 2022/02/09 15:54:09 by henkaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrr(t_stack *a, t_stack *b)
{
	int	i;
	int	temp;

	temp = a->pile[a->size - 1];
	i = a->size;
	while (--i)
		a->pile[i] = a->pile[i - 1];
	a->pile[0] = temp;
	temp = b->pile[b->size - 1];
	i = b->size;
	while (--i)
		b->pile[i] = b->pile[i - 1];
	b->pile[0] = temp;
	write(1, "rrr\n", 4);
}

int	if_one_num(char *str)
{
	long int	i;

	i = -1;
	while (str[++i])
		if (str[i] == 32 || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r')
			return (1);
	i = ft_atoi(str);
	if (i < -2147483648 || i > 2147483647)
		write(2, "Error\n", 6);
	exit(0);
}

void	check_if_sorted(t_stack *a)
{
	int	i;
	int	sorted;

	sorted = 0;
	i = 0;
	while (++i < a->size)
		if (a->pile[i - 1] > a->pile[i])
			sorted = 1;
	if (sorted == 0)
	{
		free(a->pile);
		exit (0);
	}
}

void	switch_to_index(int *fake, t_stack *a)
{
	int	i;
	int	d;
	int	*temp;

	temp = (int *)malloc(sizeof(int) * a->size);
	i = -1;
	while (++i < a->size)
	{
		d = -1;
		while (++d < a->size)
			if (a->pile[i] == fake[d])
				temp[i] = d;
	}
	i = -1;
	while (++i < a->size)
		a->pile[i] = temp[i];
	free(temp);
	free(fake);
}

void	bubble_sort(t_stack *a)
{
	int	i;
	int	temp;
	int	*fake;

	fake = (int *)malloc(sizeof(int) * a->size);
	i = -1;
	while (++i < a->size)
		fake[i] = a->pile[i];
	i = 0;
	while (++i < a->size)
	{
		while (fake[i - 1] > fake[i])
		{
			temp = fake[i];
			fake[i] = fake[i - 1];
			fake[i - 1] = temp;
			i = 1;
		}
	}
	switch_to_index(fake, a);
}
