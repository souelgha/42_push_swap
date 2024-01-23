/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort__three_five_arg.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonia <sonia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:28:05 by sonouelg          #+#    #+#             */
/*   Updated: 2024/01/23 09:49:28 by sonia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cmpn(t_stack_node *a, t_stack_node *b)
{
	if ((a->value) > (b->value))
		return (1);
	else
		return (0);
}

int	abs(int n)
{
	int a;
	
	a = n;
	if (n < 0)
		a = -n;
	return(a);
}

void	sort_three(t_stack_node **a)
{
	t_stack_node	*last;
	t_stack_node	*mid;
	t_stack_node	*one;

	last = ft_lstlast(*a);
	mid = (*a)->next;
	one = (*a);
	if ((cmpn(one, mid)) && (!cmpn(mid, last)) && (cmpn(last, one)))
		swap_a(a);
	else if ((cmpn(one, mid)) && (cmpn(mid, last)) && (!cmpn(last, one)))
	{
		swap_a(a);
		reverse_rotate_nodes_a(a);
	}
	else if ((cmpn(one, mid)) && (!cmpn(mid, last)) && (!cmpn(last, one)))
		rotate_nodes_a(a);
	else if ((!cmpn(one, mid)) && (cmpn(mid, last)) && (cmpn(last, one)))
	{
		swap_a(a);
		rotate_nodes_a(a);
	}
	else if ((!cmpn(one, mid)) && (cmpn(mid, last)) && (!cmpn(last, one)))
		reverse_rotate_nodes_a(a);
}

void	sort_uptofive(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*ptr;
	t_stack_node	*tmp;
	
	while(ft_lstsize(*a) > 3)
		push_to_b(a, b);
	sort_three(a);
	printf("Sa(%p)\n", &a);
	affiche_list(*a);
	printf("Sb(%p)\n", &b);
	affiche_list(*b);
	ptr = *b;
	while (ptr != NULL)
	{
		tmp = ptr->next;
		if (cmpn(ptr,*a) && (ptr->value - (*a)->value) > ft_lstsize(*a)/2)
		{
			while(ptr->value < (ft_lstlast(*a))->value)
				reverse_rotate_nodes_a(a);
			push_to_a(a, b);
		}
		else if (cmpn(ptr,*a) && (ptr->value - (*a)->value) <= ft_lstsize(*a)/2)
		{
			while(ptr->value > (*a)->value)
				rotate_nodes_a(a);
			push_to_a(a, b);
			while(ft_lstlast(*a)->value < (*a)->value)
				reverse_rotate_nodes_a(a);
		}
		else if (cmpn(*a,ptr) && ((*a)->value - ptr->value) < ft_lstsize(*a)/2)
		{
			while(ptr->value > (*a)->value)
				rotate_nodes_a(a);
			push_to_a(a, b);
		}
		else if (cmpn(*a,ptr)  && ((*a)->value - ptr->value) >= ft_lstsize(*a)/2)
		{
			while(cmpn(*a,ptr) && ((*a)->value - ptr->value) != 1)
					rotate_nodes_a(a);
			if (cmpn(ptr,*a))
			{
				while(ptr->value > (*a)->value)
					rotate_nodes_a(a);
			}
			push_to_a(a, b);
		}
		ptr = tmp;
	}
	while ((*a)->value != 0)
	{
		rotate_nodes_a(a);
	}
}

