#include "push_swap.h"

void	push_to_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node *nodetopush;
	t_stack_node **ptr;

	//if (!(*stack_a) || !((*stack_a)->next))
	if (!(*stack_a))
		return;
	ptr = stack_a;
	nodetopush = *stack_a;
	if ((*stack_a)->next != NULL)
	{
		(*stack_a)->next->prev = NULL;
		(*stack_a) = (*stack_a)->next;
		nodetopush->next = NULL;
		ft_add_front_node(stack_b, nodetopush);
	}	
	else
	{
	 	ft_add_front_node(stack_b, nodetopush);
		*stack_a = NULL;
	}
	write(1, "pb\n",3);
}

void	push_to_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node *nodetopush;

	if (!(*stack_b))
		return;
	nodetopush = *stack_b;  
	if ((*stack_b)->next != NULL)
	{
		(*stack_b)->next->prev = NULL;
		(*stack_b) = (*stack_b)->next;
		nodetopush->next = NULL;
		ft_add_front_node(stack_a, nodetopush);
	}
	else
	{
		ft_add_front_node(stack_a, nodetopush);
		*stack_b = NULL;
	}
	write(1, "pa\n",3);
}