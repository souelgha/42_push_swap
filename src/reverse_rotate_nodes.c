/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_nodes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:19:42 by sonouelg          #+#    #+#             */
/*   Updated: 2024/01/25 15:45:05 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_nodes(t_stack **stack)
{
	t_stack	*last_node;

	if (!(*stack) || !((*stack)->next))
		return ;
	last_node = ft_lstlast(*stack);
	last_node->next = *stack;
	(*stack)->prev = last_node;
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	*stack = last_node;
}

void	reverse_rotate_nodes_a(t_stack **stack)
{
	reverse_rotate_nodes(stack);
	write(1, "rra\n", 4);
}

void	reverse_rotate_nodes_b(t_stack **stack)
{
	reverse_rotate_nodes(stack);
	write(1, "rrb\n", 4);
}

void	reverse_rotate_nodes_ab(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate_nodes(stack_a);
	reverse_rotate_nodes(stack_b);
	write(1, "rrr\n", 4);
}
