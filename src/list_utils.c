/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:10:14 by sonouelg          #+#    #+#             */
/*   Updated: 2024/01/29 14:46:22 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/***** taille de la liste***********/
int	ft_lstsize(t_stack *lst)
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
t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*ptr;

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
void	ft_add_front_node(t_stack **lst, t_stack *new_node)
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
