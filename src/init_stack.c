/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:08:59 by sonouelg          #+#    #+#             */
/*   Updated: 2024/01/29 13:54:23 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/************ creer un new node pour chaque nombre **************/
t_stack	*ft_lstnew_node(char *str, int index)
{
	t_stack	*new_node;
	int		value;

	value = ft_atoi(str);
	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		return (NULL);
	new_node->value = value;
	new_node->index = index;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

/*********** inserer le node en fin de liste ******************/
void	ft_lstadd_back(t_stack **lst, t_stack *new_node)
{
	t_stack	*ptr;

	ptr = *lst;
	if (*lst == NULL)
	{
		*lst = new_node;
		new_node->prev = NULL;
		new_node->next = NULL;
	}
	else
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		new_node->prev = ptr;
		ptr->next = new_node;
	}
}

/*********** initialiser la stack a ******************/
void	init_stack_a(t_stack **a, char **argv)
{
	t_stack	*new_node;
	int		i;	

	i = 1;
	while (argv[i])
	{
		new_node = ft_lstnew_node(argv[i], i);
		ft_lstadd_back(a, new_node);
		i++;
	}
}
