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
/************ creer un new node avec la valeur **************/
/*t_stack_node	*ft_lstnew(int value)
{
	t_stack_node	*new;

	new = malloc(sizeof(t_stack_node));
	if (new == NULL)
		return (NULL);
	new->value = value;
	new->next = NULL;

	return (new);
}*/
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
/************ajouter un node a la fin******/
void	ft_lstadd_back(t_stack_node **lst, t_stack_node *new)
{
	t_stack_node	*ptr;
	static int		i = 0;

	ptr = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		new->prev = NULL;
		new->index = i;
//		new->value = argv[i];
	}
	else
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
		new->index = i;
//		new->value = argv[i];
	}
}
/************ajouter un node au debut de la chaine *****/
void	ft_lstadd_front(t_stack_node **lst, t_stack_node *new)
{
	if (lst != NULL && new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}	
}