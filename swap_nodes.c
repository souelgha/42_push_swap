/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:24:52 by sonouelg          #+#    #+#             */
/*   Updated: 2024/01/15 14:28:33 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack_node *stack)
{
	int	a;
	int	b;

	if (!(stack) || !(stack->next))
		return ;
	a = stack->value;
	b = stack->next->value;
	stack->value = b;
	stack->next->value = a;
}

void	swap_a(t_stack_node *stack)
{
	swap(stack);
	write(1, "sa\n", 3);
}

void	swap_b(t_stack_node *stack)
{
	swap(stack);
	write(1, "sb\n", 3);
}

void	swap_ss(t_stack_node *stack_a, t_stack_node *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
