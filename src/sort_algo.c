/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:24:17 by sonouelg          #+#    #+#             */
/*   Updated: 2024/01/29 14:44:44 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	updateindex(t_stack **a)
{
	t_stack	*ptr;
	int		i;

	i = 0;
	ptr = *a;
	while (ptr != NULL && i < ft_lstsize(*a))
	{
		ptr->index = i;
		ptr = ptr->next;
		i++;
	}
}

int	mini(t_stack *a)
{
	int		mini;
	t_stack	*ptr;

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

void	sortend(t_stack **a)
{
	while ((*a)->value != mini(*a))
		rotate_nodes_a(a);
}

void	sort(t_stack **a, t_stack **b)
{
	while (ft_lstsize (*a) > 3)
	{
		push_to_b(a, b);
	}
	sort_three(a);
	while ((*b))
	{
		target(*a, *b);
		updateindex(a);
		updateindex(b);
		cost(*a, *b);
		rotate_both_sort(a, b);
		push_to_a(a, b);
	}
	sortend(a);
}
