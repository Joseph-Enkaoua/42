/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henkaoua <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 19:28:58 by henkaoua          #+#    #+#             */
/*   Updated: 2022/02/13 04:35:26 by henkaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_it_here(t_stack *a, int min, int max)
{
	int	i;

	i = -1;
	while (++i < a->size)
		if (a->pile[i] >= min && a->pile[i] < max)
			return (1);
	return (0);
}

void	pile_setup(int ag, char **av, t_stack *a, t_stack *b)
{
	char	**temp;
	int		i;

	i = 0;
	if (ag < 2)
		exit(0);
	else if (ag == 2)
	{
		if (av[1][0] == '\0')
			exit(0);
		if_one_num(av[1]);
		temp = ft_split(av[1], ' ');
	}
	if (ag > 2)
	{
		temp = (char **)malloc(ag * sizeof(char *));
		while (++i < ag)
			temp[i - 1] = malloc_it(av[i]);
		temp[i - 1] = 0;
	}
	a->pile = check_validity(temp, a, b);
	check_if_sorted(a);
}

int	main(int ag, char **av)
{
	t_stack	a;
	t_stack	b;

	pile_setup(ag, av, &a, &b);
	bubble_sort(&a);
	if (a.size == 2)
		sa(&a);
	else if (a.size == 3)
		check_if_sorted(triple_sort(&a));
	else if (a.size > 3 && a.size < 6)
		small_sort(&a, &b);
	else if (a.size > 5 && a.size < 121)
		big_sort(&a, &b, 28);
	else if (a.size > 120 && a.size < 301)
		big_sort(&a, &b, 48);
	else if (a.size > 300 && a.size < 501)
		big_sort(&a, &b, 72);
	if (a.size > 500)
		big_sort(&a, &b, 75);
	free(a.pile);
	return (0);
}
