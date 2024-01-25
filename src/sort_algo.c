/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:24:17 by sonouelg          #+#    #+#             */
/*   Updated: 2024/01/25 14:05:46 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	updateindex(t_stack_node **a)
{
	t_stack_node	*ptr;
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

void	find_max(t_stack_node **a, int *maxtop, int *maxbottom)
{
	t_stack_node	*ptr;
	int				size;

	ptr = *a;
	size =ft_lstsize(*a);
//	printf("\033[0;34m" "size=%d\n" "\x1B[0m", size);
	*maxtop = ptr->value;
	while (ptr->index < 10 && ptr->index < size/2)
	{
//		printf("\033[0;32m" "ptrin=%d, val=%d\n" "\x1B[0m", ptr->index, ptr->value);
		if (*maxtop < ptr->next->value)
			*maxtop = ptr->next->value;
		ptr = ptr->next;
	}
	ptr = ft_lstlast(*a);
	*maxbottom = ptr->value;
	while (ptr->index > (size - 10) && ptr->index > size/2 )
	{
//		printf("\033[0;34m" "ptrin=%d, val=%d\n" "\x1B[0m", ptr->index, ptr->value);
		if (*maxbottom < ptr->prev->value)
			*maxbottom = ptr->prev->value;
		ptr = ptr->prev;
	}
}
/***trouver la position du node a dans b *******/
int findpos(t_stack_node **a, t_stack_node **b)
{
	t_stack_node *ptr;
	int				i;

	i = 0;
	ptr = *b;
	while(cmpn(ptr, (*a)) && ptr->next != NULL)
		ptr = ptr->next;
	i = ptr->index;
	return (i);
}
void sort(t_stack_node **a, t_stack_node **b)
{
	int	maxtop;
	int	maxbottom;
	int	indtop;
	int	indbottom;
	t_stack_node	*ptr;
	
	while (ft_lstsize(*a) > 3)
	{
		find_max(a,&maxtop, &maxbottom);
		indbottom = 0;
		indtop = 0;
		ptr = *a;
		while (ptr->value != maxtop)
		{
			indtop++;
			ptr = ptr->next;
		}
		while (ptr->value != maxbottom)
		{
			indbottom++;
			ptr = ptr->next;
		}			
		if(indtop < (ft_lstsize(*a) - indbottom - indtop))
		{
			while ((*a)->value != maxtop)
				rotate_nodes_a(a);			
		}
		else 
		{
		 	while ((*a)->value != maxbottom)
		 		reverse_rotate_nodes_a(a);
		}
		if (ft_lstsize(*b) == 0  || ft_lstsize(*b) == 1 )
			push_to_b(a,b);
		else if(ft_lstsize(*b) == 2 && check_sort(*b))
			swap_b(b);
		else if ((*a)->value < mini(*b) && ft_lstsize(*b) >= 2)
		{
			push_to_b(a,b);
			rotate_nodes_b(b);
		}
		else
		{
			indtop = findpos(a, b);
		//	printf("\033[0;34m" "index=%d, middle=%d\n" "\x1B[0m", indtop, ft_lstsize(*b)/2);
			if (indtop <= ft_lstsize(*b)/2)
			{
				while((*b)->index != indtop)
					rotate_nodes_b(b);
				push_to_b(a, b);
				while((*b)->value != maxi(*b))
					reverse_rotate_nodes_b(b);
			}
			if (indtop > ft_lstsize(*b)/2)
			{
				while((*b)->index != indtop)
					reverse_rotate_nodes_b(b);
				push_to_b(a, b);
				while((*b)->value != maxi(*b))
					rotate_nodes_b(b);
			}
		}
		updateindex(a);
		updateindex(b);
	}
	sort_three(a);
	ptr = *b;
	while (ptr!= NULL)
	{
		push_to_a(a, b);
		// printf("\033[0;34m" "*a=%p, *b=%p\n" "\x1B[0m", *a, *b);
		// printf("\033[0;34m" "ptr=%p, next=%p\n" "\x1B[0m", ptr, ptr->next);
		ptr = *b;
	}
	while((*a)->value != 0)
		reverse_rotate_nodes_a(a);
}
