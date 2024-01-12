#include "push_swap.h"

/***************swap des 2  premiers elements de la stack**********/
void swap_a(t_stack_node *stack)
{
	int a;
	int	b;

	if( !(stack) || !(stack->next))
		return;
	a = stack->value;
	b = stack->next->value;
	stack->value = b;
	stack->next->value = a;
	write(1, "sa\n",3);

}

void swap_b(t_stack_node *stack)
{
	int a;
	int	b;

	if(!stack || !(stack->next))
		return;
	a = stack->value;
	b = stack->next->value;
	stack->value = b;
	stack->next->value = a;
	write(1, "sb\n",3);


}

void swap_ss(t_stack_node *stack_a, t_stack_node *stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
	write(1, "ss\n",3);


}
