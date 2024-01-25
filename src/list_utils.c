/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:10:14 by sonouelg          #+#    #+#             */
/*   Updated: 2024/01/25 13:44:11 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

/************ajouter un node au debut de la chaine *****/
void	ft_add_front_node(t_stack_node **lst, t_stack_node *new_node)
{
	if (*lst == NULL)
	{
		*lst = new_node;
		new_node->prev = NULL;
		new_node->next = NULL;
	}
	else
	{
		new_node->next = *lst;
		new_node->next->prev = new_node;
		new_node->prev = NULL;
		*lst = new_node;
	}
}

/*********afficher la liste****************/
 void	affiche_list(t_stack_node *lst)
{
	t_stack_node	*ptr;	
	if (!lst)
		return ;
	ptr = lst;
	printf("lst_Add=(%p)\n", ptr);
	while (ptr != NULL)
	{
		printf("nb=%d\tindex=%d\t\n", ptr->value, ptr->index);
	//	printf("Add=(%p)\tnext=(%p)\tprev=(%p)\n", ptr, ptr->next, ptr->prev);
		ptr = ptr->next;
	}
}
/******affichage de debug */
// void	affiche_status(t_stack_node **lst)
// {
// 	t_stack_node	*ptr;

// 	if (!lst)
// 		return;
// 	ptr = *lst;
// 	printf("lst_Add=(%p)\n", ptr);
// 	while (ptr->next != NULL)
// 	{
// 		printf("value_node=%d\tindex=%d\tindex_final=%d\t", ptr->value, ptr->index, ptr->index_final);
// 		if(ptr->prev != NULL)
// 			printf("prev_value=%d\t", ptr->prev->value);
// 		else
// 			printf("prev_value=NULL\t");
// 		printf("next_value=%d\t\n", ptr->next->value);	
// 		ptr = ptr->next;
// 	}
// 	if (ptr == ft_lstlast(*lst))
// 	{
// 		printf("value_node=%d\tindex=%d\tindex_final=%d\t", ptr->value, ptr->index, ptr->index_final);
// 		printf("prev_value=%d\tnext_value=NULL\t", ptr->prev->value);
// 	}
//}