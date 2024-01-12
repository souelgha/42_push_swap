#include "push_swap.h"

void	push_to_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node *nodetopush;

	if (!stack_a)
		return;
	nodetopush = *stack_a;
	if ((*stack_a)->next != NULL)
	{
		*stack_a = (*stack_a)->next;
		(*stack_a)->prev = NULL;
		nodetopush->next = NULL;
		nodetopush->prev = NULL;
		ft_add_front_node(stack_b, nodetopush);
	}
	else
		ft_add_front_node(stack_b, nodetopush);
	write(1, "pb\n",3);
}

void	push_to_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node *nodetopush;

	if (!stack_b)
		return;
	nodetopush = *stack_b;  
	if ((*stack_b)->next != NULL)
	{
		*stack_b = (*stack_b)->next;
		(*stack_b)->prev = NULL;
		nodetopush->next = NULL;
		nodetopush->prev = NULL;
		ft_add_front_node(stack_a, nodetopush);
	}
	else
	{
		ft_add_front_node(stack_a, nodetopush);
	}
	write(1, "pa\n",3);
}