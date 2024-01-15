#include "push_swap.h"

int	check_sort(t_stack_node *stack_a)
{
	t_stack_node *ptr;

	if (!stack_a)
		return (-1);
	ptr = stack_a;
	while (ptr->next != NULL)
	{
		if((ptr->value) > (ptr->next->value))
			return(0);
		ptr= ptr->next;						
	}
	return (1);
}

void	sort_two(t_stack_node *stack_a)
{
	int	a;
	int	b;

	a = stack_a->value;
	b = stack_a->next->value;
	stack_a->value = b;
	stack_a->next->value = a;
	
}

