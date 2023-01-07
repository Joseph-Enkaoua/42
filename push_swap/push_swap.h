/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henkaoua <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:10:06 by henkaoua          #+#    #+#             */
/*   Updated: 2022/02/15 17:08:19 by henkaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_stack {
	int	*pile;
	int	size;
}	t_stack;

typedef struct s_mark {
	int	initial_size;
	int	hold_first;
	int	hold_last;
	int	call;
	int	last_call;
	int	i;
	int	min;
	int	max;
}	t_mark;

char	*malloc_it(char *str);
int		*check_validity(char **str, t_stack *a, t_stack *b);
void	sa(t_stack *a);
void	sb(t_stack *a);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
int		if_one_num(char *str);
void	check_if_sorted(t_stack *a);
void	switch_to_index(int *fake, t_stack *a);
void	bubble_sort(t_stack *a);
void	big_sort(t_stack *a, t_stack *b, int num);
t_stack	*triple_sort(t_stack *a);
void	small_sort(t_stack *a, t_stack *b);
int		buzz_th_tower(t_stack *a);
int		walk_in_the_park(t_stack *a);
void	compensation(t_stack *a, t_mark *ar, int last_a);
void	min_up_won(t_stack *a, t_stack *b, int *min);
void	max_up_won(t_stack *a, t_stack *b, int *max, int *t);
void	min_down_won(t_stack *a, t_stack *b, int *min);
void	max_down_won(t_stack *a, t_stack *b, int *max, int *t);
int		is_it_here(t_stack *a, int min, int max);
#endif
