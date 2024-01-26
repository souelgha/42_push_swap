/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:01:02 by sonouelg          #+#    #+#             */
/*   Updated: 2024/01/26 16:41:53 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	target(t_stack *a, t_stack *b)
{
	t_stack	*ptr;
	t_stack	*target;
	int		match_value;

	while (b)
	{
		match_value = INT_MAX;
		ptr = a;
		while (ptr)
		{
			if (ptr->value > b->value && ptr->value < match_value)
			{
				match_value = ptr->value;
				target = ptr;
			}
			ptr = ptr->next;
			if (INT_MAX == match_value)
				b->target = smallest(a);
			else
				b->target = target;
		}
		b = b->next;
	}
}

t_stack	*smallest(t_stack *a)
{
	t_stack	*small;

	small = a;
	while (a)
	{
		if (a->value < small->value)
			small = a;
		a = a->next;
	}
	return (small);
}

void	cost(t_stack *a, t_stack *b)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(a);
	size_b = ft_lstsize(b);
	while (b)
	{	
		b->cost = b->index;
		if (b->index > size_b / 2)
			b->cost = size_b - b->index;
		if (b->target->index <= size_a / 2)
			b->cost = b->cost + b->target->index;
		else if (b->target->index > size_a / 2)
			b->cost = b->cost + size_a - b->target->index;
		b = b->next;
	}	
}

t_stack	*cheapest(t_stack *b)
{
	t_stack	*cheap;

	cheap = b;
	while (b)
	{		
		if (b->cost < cheap->cost)
			cheap = b;
		b = b->next;
	}
	return (cheap);
}

void rotate_both_sort (t_stack **a, t_stack **b)
{
	t_stack	*ptr;
	int		mid_a;
	int		mid_b;

	mid_a = ft_lstsize(*a) / 2;
	mid_b = ft_lstsize(*b) / 2;
	//printf("\033[0;34m" "mid_a=%d\tmid_b=%d\t\n" "\x1B[0m", mid_a, mid_b);
	ptr = cheapest(*b);
	//printf("\033[0;35m" "ptr=(%p)\tcheapval=%d\ta(%p)\tb(%p)\nindex=%d\ttarget(%p)\n" "\x1B[0m", ptr, ptr->value, *a, *b, ptr->index, ptr->target);
	if (ptr->index <= mid_b && ptr->target->index < mid_a)
	{
		while (*b != ptr && *a != ptr->target)
			rotate_nodes_ab(a, b);
		while (*b != ptr)
			rotate_nodes_b(b);
		while (*a != ptr->target)
			rotate_nodes_a(a);
	//	printf("\033[0;34m" "ptr=(%p)\tcheapval=%d\t\n" "\x1B[0m", ptr, ptr->value);
	}
	else if (ptr->index > mid_b && ptr->target->index >= mid_a)
	{
		while (*b != ptr && *a != ptr->target)
			reverse_rotate_nodes_ab(a, b);
		while (*b != ptr)
			reverse_rotate_nodes_b(b);
		while (*a != ptr->target)
			reverse_rotate_nodes_a(a);
	}
	else if (ptr->index <= mid_b && ptr->target->index >= mid_a)
	{
		while (*b != ptr)
			rotate_nodes_b(b);
		while (*a != ptr->target)
			reverse_rotate_nodes_a(a);
	}
	else if (ptr->index > mid_b && ptr->target->index < mid_a)
	{
		while (*b != ptr)
			reverse_rotate_nodes_b(b);
		while (*a != ptr->target)
			rotate_nodes_a(a);
	}
}		
		// printf("\033[0;33m" "a=(%p)\tval=%d\t\n", a, a->value);
		// printf("small=(%p)\tval= %d\n" "\x1B[0m", small, small->value);