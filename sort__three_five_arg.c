/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort__three_five_arg.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:28:05 by sonouelg          #+#    #+#             */
/*   Updated: 2024/01/17 17:31:52 by sonouelg         ###   ########.fr       */
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

void	sort_five(t_stack_node **a, t_stack_node **b, int size)
{
	t_stack_node	*last_b;
	t_stack_node	*last_a;
	int n;

	last_b = ft_lstlast(*b);
	last_a = ft_lstlast(*a);
	
	push_to_b(a, b);
	push_to_b(a, b);
	sort_three(a);
	last_a = ft_lstlast(*a);
	printf("lasta=%d\t *b=%d\n", last_a->value, (*b)->value);
	n = (*b)->index_final - (*a)->index_final;
	printf("n=%d, abs(n)=%d\n", n, abs(n));
 	/****conditon 1*****/
	if (abs(n) < size/2)
	{
		if (n > 0)
		{
			rotate_nodes_a(a);
			push_to_a(a, b);
			reverse_rotate_nodes_a(a);
		}
		/****conditon 2*****/
		else if (n < 0)
			push_to_a(a, b);
		if ((*b)->index_final == 4)
		{
			push_to_a(a, b);
			rotate_nodes_a(a);
		}
		else if ((*b)->index_final == 0)
			push_to_a(a, b);
	}

}
	
	
	
	
	
	
	/***comdition a index 0 au top de b****/
	
	// if (((*a)->index_final - (*b)->index_final) == 1 && (*b)->index_final == 0)
	//  	push_to_a(a, b);
	




	/**remettre le topnode de b au bon endroit***/
	// if (last_a->index_final > (*b)->index_final) 
	// {
	// 	if ((last_a->index_final - (*b)->index_final) >= (size)/2)
	// 	{
	// 		rotate_nodes_a(a);
	// 		push_to_a(a, b);
	// 		push_to_a(a, b);
	// 		reverse_rotate_nodes_a(a);
	// 	}
	// 	else if ((last_a->index_final - (*b)->index_final) < (size)/2)
	// 	{
	// 		reverse_rotate_nodes_a(a);
	// 		push_to_a(a, b);
	// 		reverse_rotate_nodes_a(a);
	// 		reverse_rotate_nodes_a(a);
	// 	}
	// }
	// /***condition 2 ***/
	// if ((last_a->value < (*b)->value))
	// {
	// 	if ((last_a->index_final - (*b)->index_final) < (size)/2)
	// 	{
	// 		push_to_a(a, b);
	// 		reverse_rotate_nodes_a(a);		
	// 		push_to_a(a, b);
	// 		rotate_nodes_a(a);
	// 		rotate_nodes_a(a);
	// 		rotate_nodes_a(a);
	// 	}
	// }
		
	/*if ((last_a->value > (*b)->value) && (last_a->index_final - (*b)->index_final) >= (size)/2)
	{
		rotate_nodes_a(a);
		push_to_a(a, b);
		push_to_a(a, b);
		reverse_rotate_nodes_a(a);
	}*/

