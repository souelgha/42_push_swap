/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:24:17 by sonouelg          #+#    #+#             */
/*   Updated: 2024/01/26 16:45:33 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	updateindex(t_stack **a)
{
	t_stack	*ptr;
	int				i;

	i = 0;
	ptr = *a;
	while (ptr != NULL && i < ft_lstsize(*a))
	{
		ptr->index = i;
		ptr = ptr->next;
		i++;
	}
}

void	sort(t_stack **a, t_stack **b)
{
	while(ft_lstsize (*a) > 3)
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
