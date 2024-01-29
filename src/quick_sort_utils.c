/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:01:02 by sonouelg          #+#    #+#             */
/*   Updated: 2024/01/29 15:59:35 by sonouelg         ###   ########.fr       */
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
