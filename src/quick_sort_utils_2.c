/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:20:10 by sonouelg          #+#    #+#             */
/*   Updated: 2024/01/29 16:00:52 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rot_index_top(t_stack **a, t_stack **b, t_stack *ptr)
{
	while (*b != ptr && *a != ptr->target)
		rotate_nodes_ab(a, b);
	while (*b != ptr)
		rotate_nodes_b(b);
	while (*a != ptr->target)
		rotate_nodes_a(a);
}

static void	rot_index_bottom(t_stack **a, t_stack **b, t_stack *ptr)
{
	while (*b != ptr && *a != ptr->target)
		reverse_rotate_nodes_ab(a, b);
	while (*b != ptr)
		reverse_rotate_nodes_b(b);
	while (*a != ptr->target)
		reverse_rotate_nodes_a(a);
}

static void	rot_top_bottom(t_stack **a, t_stack **b, t_stack *ptr)
{
	while (*b != ptr)
		rotate_nodes_b(b);
	while (*a != ptr->target)
		reverse_rotate_nodes_a(a);
}

static void	rot_bottom_top(t_stack **a, t_stack **b, t_stack *ptr)
{
	while (*b != ptr)
		reverse_rotate_nodes_b(b);
	while (*a != ptr->target)
		rotate_nodes_a(a);
}

void	rotate_both_sort(t_stack **a, t_stack **b)
{
	t_stack	*ptr;
	int		mid_a;
	int		mid_b;

	mid_a = ft_lstsize(*a) / 2;
	mid_b = ft_lstsize(*b) / 2;
	ptr = cheapest(*b);
	if (ptr->index <= mid_b && ptr->target->index < mid_a)
		rot_index_top(a, b, ptr);
	else if (ptr->index > mid_b && ptr->target->index >= mid_a)
		rot_index_bottom(a, b, ptr);
	else if (ptr->index <= mid_b && ptr->target->index >= mid_a)
		rot_top_bottom(a, b, ptr);
	else if (ptr->index > mid_b && ptr->target->index < mid_a)
		rot_bottom_top(a, b, ptr);
}
