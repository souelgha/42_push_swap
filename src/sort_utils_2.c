/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:28:44 by sonouelg          #+#    #+#             */
/*   Updated: 2024/01/24 14:09:02 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	firstcase(t_stack_node **a, t_stack_node **b)
{
	case_inrev_rotate_a(a, b);
	push_to_a(a, b);
}

void	secondcase(t_stack_node **a, t_stack_node **b)
{
	case_rotate_a(a, b);
	push_to_a(a, b);
	case_rev_rotate_a(a);
}

void	thirdcase(t_stack_node **a, t_stack_node **b)
{
	case_rotate_a(a, b);
	push_to_a(a, b);
}

void	forthcase(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*ptr;
//	int				diff;

	ptr = *b;
	// diff = ((*a)->value - ptr->value);
	// while (cmpn(*a, ptr) && diff != 1)
	// 	rotate_nodes_a(a);
	// if (cmpn(ptr,*a))
	// 	case_rotate_a(a, b);
	push_to_a(a, b);
}

void	sortend(t_stack_node **a)
{
	while ((*a)->value != 0)
		rotate_nodes_a(a);
}
