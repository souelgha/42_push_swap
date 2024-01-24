/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:54:19 by sonia             #+#    #+#             */
/*   Updated: 2024/01/24 10:27:06 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_rotate_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*ptr;

	ptr = *b;
	if (ptr->value > maxi(*a))
	{
		while ((*a)->value != mini(*a))
			rotate_nodes_a(a);
	}
	else
	{
		while (ptr->value > (*a)->value)
			rotate_nodes_a(a);
	}
}

void	case_rev_rotate_a(t_stack_node **a)
{	
	while (ft_lstlast(*a)->value < (*a)->value)
		reverse_rotate_nodes_a(a);
}

void	case_inrev_rotate_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*ptr;

	ptr = *b;
	if (ptr->value < mini(*a))
	{
		while ((*a)->value != mini(*a))
			rotate_nodes_a(a);
	}
	else
	{
		while (ptr->value < (ft_lstlast(*a))->value)
			reverse_rotate_nodes_a(a);
	}
}

int	maxi(t_stack_node *a)
{
	int				maxi;
	t_stack_node	*ptr;

	ptr = a;
	maxi = a->value;
	while (ptr->next != NULL)
	{
		if (maxi < ptr->next->value)
			maxi = ptr->next->value;
		ptr = ptr->next;
	}
	return (maxi);
}

int	mini(t_stack_node *a)
{
	int				mini;
	t_stack_node	*ptr;

	ptr = a;
	mini = a->value;
	while (ptr->next != NULL)
	{
		if (mini > ptr->next->value)
			mini = ptr->next->value;
		ptr = ptr->next;
	}
	return (mini);
}
