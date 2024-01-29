/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:28:05 by sonouelg          #+#    #+#             */
/*   Updated: 2024/01/29 14:37:41 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/****verifie si la pile est deja triee ********/
int	check_sort(t_stack *stack_a)
{
	t_stack	*ptr;

	if (!stack_a)
		return (-1);
	ptr = stack_a;
	while (ptr->next != NULL)
	{
		if ((ptr->value) > (ptr->next->value))
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

int	cmpn(t_stack *a, t_stack *b)
{
	if ((a->value) > (b->value))
		return (1);
	else
		return (0);
}

void	sort_three(t_stack **a)
{
	t_stack	*last;
	t_stack	*mid;
	t_stack	*one;

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
