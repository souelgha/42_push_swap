#include "push_swap.h"

/** ******free la list *************/
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
/***** taille de la liste***********/
int	ft_lstsize(t_stack_node *lst)
{
	size_t	size;

	if (!lst)
		return (0);
	size = 1;
	while (lst->next != NULL)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
/************ new node**************/
t_stack_node	*ft_lstnew(int value)
{
	t_stack_node	*new;

	new = malloc(sizeof(t_stack_node));
	if (new == NULL)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}
/***********trouver le dernier *****/
t_stack_node	*ft_lstlast(t_stack_node *lst)
{
	t_stack_node	*ptr;

	ptr = lst;
	if (lst == NULL)
		return (lst);
	else
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		return (ptr);
	}
}
