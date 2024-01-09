#include "push_swap.h"

/** free la list */
void	ft_lstclear(t_stack_node **lst)
{
	t_stack_node	*tmp;

	if (!lst)
		return ;
	tmp = NULL;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		free(*lst);
		(*lst) = tmp;
	}
	*lst = NULL;
}
