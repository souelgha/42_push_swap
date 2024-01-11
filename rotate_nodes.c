#include "push_swap.h"

void	rotate_nodes_a(t_stack_node *stack)
{
	
	t_stack_node	*top;
	t_stack_node	*ptr;
	t_stack_node	*head;

	head = stack;
	ptr = ft_lstlast(head); // le dernier de la stack
	top = stack->next;
	printf("head:(%p) ; stack:(%p)\n", head, stack);
	printf("ptr:(%p) \n", ptr);
	printf("new head ; top:(%p)\n", top);
	// stack = stack->next;
	// printf("new head ; stack->next:(%p)\n", stack)
	ptr->next = head;
	printf("head:(%p) ; ptr->next:(%p)\n", head, ptr->next);
	head->prev = ptr;
	head->next = NULL;
	top->prev = NULL;
	// stack = stack->next;
	stack = top;
	printf("top:(%p) ; stack:(%p)\n", top, stack);
	write(1, "ra\n", 3);
}