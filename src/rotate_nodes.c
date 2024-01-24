/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:19:47 by sonouelg          #+#    #+#             */
/*   Updated: 2024/01/15 14:24:19 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_nodes(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!(*stack) || !((*stack)->next))
		return ;
	last_node = ft_lstlast(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	rotate_nodes_a(t_stack_node **stack)
{
	rotate_nodes(stack);
	write(1, "ra\n", 3);
}

void	rotate_nodes_b(t_stack_node **stack)
{
	rotate_nodes(stack);
	write(1, "rb\n", 3);
}

void	rotate_nodes_ab(t_stack_node **stack_a, t_stack_node **stack_b)
{
	rotate_nodes(stack_a);
	rotate_nodes(stack_b);
	write(1, "rr\n", 3);
}
