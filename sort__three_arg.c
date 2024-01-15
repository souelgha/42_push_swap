/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort__three_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:28:05 by sonouelg          #+#    #+#             */
/*   Updated: 2024/01/15 17:42:07 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cmpnode(t_stack_node *a, t_stack_node *b)
{
	if ((a->value) > (b->value))
		return (1);
	else
		return (0);
}

void	sort_three(t_stack_node *a)
{
	t_stack_node	*last;
	t_stack_node	*mid;

	last = ft_lstlast(a);
	mid = (a)->next;
	if ((cmpnode(a, mid)) && (cmpnode(last, a)) && (!cmpnode(mid, last)))
		swap_a(a);
	else if ((cmpnode(a, mid)) && (!cmpnode(last, a)) && (cmpnode(mid, last)))
	{
		swap_a(a);
		reverse_rotate_nodes_a(&a);
	}
	else if ((cmpnode(a, mid)) && (!cmpnode(last, a)) && (!cmpnode(mid, last)))
		rotate_nodes_a(&a);
	else if ((!cmpnode(a, mid)) && (cmpnode(last, a)) && (cmpnode(mid, last)))
	{
		swap_a(a);
		rotate_nodes_a(&a);
	}
	else if ((!cmpnode(a, mid)) && (cmpnode(last, a)) && (!cmpnode(mid, last)))
		reverse_rotate_nodes_a(&a);
}
