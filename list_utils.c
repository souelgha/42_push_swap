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

/************ajouter un node au debut de la chaine *****/
void	ft_lstadd_front(t_stack_node **lst, t_stack_node *new)
{
	if (lst != NULL && new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}	
}
void	ft_add_front_node(t_stack_node **lst, t_stack_node *new_node)
{
//	t_stack_node	*ptr;

//	ptr = *lst;
	if (*lst == NULL)
	{
		*lst = new_node;
		new_node->prev = NULL;
		new_node->next = NULL;
	}
	else
	{
		new_node->next = *lst;
		new_node->prev = NULL;
		*lst = new_node;
	}
}

/*********afficher la liste****************/
void	affiche_list(t_stack_node *lst)
{
	t_stack_node	*ptr;

	ptr = lst;
	while (ptr != NULL)
	{
		printf("nb=%d, i=%d\n", ptr->value, ptr->index);
		ptr = ptr->next;
	}
}