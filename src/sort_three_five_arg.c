/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort__three_five_arg.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:28:05 by sonouelg          #+#    #+#             */
/*   Updated: 2024/01/24 10:30:44 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cmpn(t_stack_node *a, t_stack_node *b)
{
	if ((a->value) > (b->value))
		return (1);
	else
		return (0);
}

void	sort_three(t_stack_node **a)
{
	t_stack_node	*last;
	t_stack_node	*mid;
	t_stack_node	*one;

	last = ft_lstlast(*a);
	mid = (*a)->next;
	one = (*a);
	if ((cmpn(one, mid)) && (!cmpn(mid, last)) && (cmpn(last, one)))
		swap_a(a);
	else if ((cmpn(one, mid)) && (cmpn(mid, last)) && (!cmpn(last, one)))
	{
		swap_a(a);
		reverse_rotate_nodes_a(a);
	}
	else if ((cmpn(one, mid)) && (!cmpn(mid, last)) && (!cmpn(last, one)))
		rotate_nodes_a(a);
	else if ((!cmpn(one, mid)) && (cmpn(mid, last)) && (cmpn(last, one)))
	{
		swap_a(a);
		rotate_nodes_a(a);
	}
	else if ((!cmpn(one, mid)) && (cmpn(mid, last)) && (!cmpn(last, one)))
		reverse_rotate_nodes_a(a);
}

void	sizeuptothree(t_stack_node **a, t_stack_node **b)
{
	while (ft_lstsize(*a) > 3)
		push_to_b(a, b);
}

void	sort_uptofive(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*ptr;
	t_stack_node	*tmp;
	int				diff;

	sizeuptothree(a, b);
	sort_three(a);
	ptr = *b;
	while (ptr != NULL)
	{
		diff = ((*a)->value - ptr->value);
		tmp = ptr->next;
		slt(a, b, diff, ptr);
		ptr = tmp;
	}
	sortend(a);
}

void	slt(t_stack_node **a, t_stack_node **b, int diff, t_stack_node *ptr)
{
	t_stack_node	*last;	
	int				middle;

	middle = ft_lstsize(*a) / 2;
	last = ft_lstlast(*a);
	if (cmpn(ptr, *a) && (-diff > middle))
		firstcase(a, b);
	else if (cmpn(ptr, *a) && (-diff <= middle))
		secondcase(a, b);
	else if (cmpn(*a, ptr) && diff < middle)
		thirdcase(a, b);
	else if (cmpn(*a, ptr) && cmpn(*a, last) && diff >= middle)
		firstcase(a, b);
	else if (cmpn(*a, ptr) && !cmpn(*a, last) && diff >= middle)
		forthcase(a, b);
}
