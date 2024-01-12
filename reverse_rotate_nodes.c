#include "push_swap.h"

void	reverse_rotate_nodes_a(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if( !(*stack) || !((*stack)->next))
			return;	
	last_node = ft_lstlast(*stack); 
	last_node->next  = *stack;
	(*stack)->prev = last_node;
	last_node->prev->next= NULL;
	last_node->prev = NULL;	
	*stack = last_node;	
	write(1, "rra\n", 4);

}

void	reverse_rotate_nodes_b(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if( !(*stack) || !((*stack)->next))
			return;	
	last_node = ft_lstlast(*stack); 
	last_node->next  = *stack;
	(*stack)->prev = last_node;
	last_node->prev->next= NULL;
	last_node->prev = NULL;	
	*stack = last_node;	
	write(1, "rrb\n", 4);

}


void	reverse_rotate_nodes_ab(t_stack_node **stack_a, t_stack_node **stack_b)
{
	reverse_rotate_nodes_a(stack_a);
	reverse_rotate_nodes_b(stack_b);
	write(1, "rrr\n", 4);

}