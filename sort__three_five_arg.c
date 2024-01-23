/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort__three_five_arg.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonia <sonia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:28:05 by sonouelg          #+#    #+#             */
/*   Updated: 2024/01/23 16:44:40 by sonia            ###   ########.fr       */
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

void	sizeuptothree(t_stack_node **a, t_stack_node **b)
{
	while(ft_lstsize(*a) > 3)
		push_to_b(a, b);
}

void	sort_uptofive(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*ptr;
	t_stack_node	*tmp;
	
	sizeuptothree(a, b);
	sort_three(a);
	/*printf("Sa(%p)\n", &a);
	affiche_list(*a);	
	printf("Sb(%p)\n", &b);
	affiche_list(*b);;
	printf("\n");*/
	ptr = *b;
	while (ptr != NULL)
	{
		tmp = ptr->next;
		if (cmpn(ptr, *a) && (ptr->value - (*a)->value) > ft_lstsize(*a)/2)
		{
			case_inrev_rotate_a(a, b);
			push_to_a(a, b);
		}
		else if (cmpn(ptr, *a) && (ptr->value - (*a)->value) <= ft_lstsize(*a)/2)
		{
			case_rotate_a(a, b);
			push_to_a(a, b);
			case_rev_rotate_a(a);
		}
		else if (cmpn(*a, ptr) && ((*a)->value - ptr->value) < ft_lstsize(*a)/2)
		{
			case_rotate_a(a, b);
			push_to_a(a, b);
		}
		else if (cmpn(*a, ptr) && cmpn(*a, ft_lstlast(*a)) && ((*a)->value - ptr->value) >= ft_lstsize(*a)/2)
		{
			case_inrev_rotate_a(a, b);
			push_to_a(a, b);
		}
		else if (cmpn(*a, ptr)  && !cmpn(*a, ft_lstlast(*a)) && ((*a)->value - ptr->value) >= ft_lstsize(*a)/2)
		{
			while (cmpn(*a, ptr) && ((*a)->value - ptr->value) != 1)
				rotate_nodes_a(a);
			if (cmpn(ptr,*a))
				case_rotate_a(a, b);
			push_to_a(a, b);
		}
	//	printf("max=%d\n", maxi(*a));
	//	printf("min=%d\n", mini(*a));
		ptr = tmp;
	/*	printf("Sa(%p)\n", &a);
		affiche_list(*a);	
		printf("Sb(%p)\n", &b);
		affiche_list(*b);;
		printf("\n");*/
	}
	while ((*a)->value != 0)
		rotate_nodes_a(a);

	/*printf("Sa(%p)\n", &a);
	affiche_list(*a);	
	printf("Sb(%p)\n", &b);
	affiche_list(*b);;
	printf("\n");*/
}

