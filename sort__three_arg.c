#include "push_swap.h"

int	compnode(t_stack_node *a, t_stack_node *b)
{
	if ((a->value) > (b->value))
		return (1);
	else
		return (0);
}
void	sort_three_args(t_stack_node *a)
{
	if (compnode(a, a->next))
		write(1, "+", 1);
}