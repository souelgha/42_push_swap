/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:28:44 by sonouelg          #+#    #+#             */
/*   Updated: 2024/01/25 15:45:05 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	firstcase(t_stack **a, t_stack **b)
{
	case_inrev_rotate_a(a, b);
	push_to_a(a, b);
}

void	secondcase(t_stack **a, t_stack **b)
{
	case_rotate_a(a, b);
	push_to_a(a, b);
	case_rev_rotate_a(a);
}

void	thirdcase(t_stack **a, t_stack **b)
{
	case_rotate_a(a, b);
	push_to_a(a, b);
}

void	forthcase(t_stack **a, t_stack **b)
{
	t_stack	*ptr;
//	int				diff;

	ptr = *b;
	// diff = ((*a)->value - ptr->value);
	// while (cmpn(*a, ptr) && diff != 1)
	// 	rotate_nodes_a(a);
	// if (cmpn(ptr,*a))
	// 	case_rotate_a(a, b);
	push_to_a(a, b);
}

void	sortend(t_stack **a)
{
	while ((*a)->value != 0)
		rotate_nodes_a(a);
}
