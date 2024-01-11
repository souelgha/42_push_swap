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
	int a;
	int	b;

	a = stack_a->value;
	b = stack_a->next->value;
	stack_a->value = b;
	stack_a->next->value = a;
	a = stack_b->value;
	b = stack_b->next->value;
	stack_b->value = b;
	stack_b->next->value = a;
	write(1, "ss\n",3);


}
