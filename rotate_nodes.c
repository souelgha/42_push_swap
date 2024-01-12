#include "push_swap.h"

void	rotate_nodes_a(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if( !(*stack) || !((*stack)->next))
			return;	
	last_node = ft_lstlast(*stack); 
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;

	last_node->next->prev = last_node;
	last_node->next->next = NULL;
	write(1, "ra\n", 3);

}

void	rotate_nodes_b(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if( !(*stack) || !((*stack)->next))
			return;	
	last_node = ft_lstlast(*stack); 
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;

	last_node->next->prev = last_node;
	last_node->next->next = NULL;
	write(1, "rb\n", 3);

}

void	rotate_nodes_ab(t_stack_node **stack_a, t_stack_node **stack_b)
{
	rotate_nodes_a(stack_a);
	rotate_nodes_b(stack_b);
	write(1, "rr\n", 3);

}