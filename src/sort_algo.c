/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:24:17 by sonouelg          #+#    #+#             */
/*   Updated: 2024/01/24 18:22:37 by sonouelg         ###   ########.fr       */
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
	//int 			i;

	ptr = *a;
	size =ft_lstsize(*a);
	printf("\033[0;34m" "size=%d\n" "\x1B[0m", size);
	*maxtop = ptr->value;
	while (ptr->index < 5)
	{
		if (*maxtop < ptr->next->value)
			*maxtop = ptr->next->value;
		ptr = ptr->next;
	}
	ptr = ft_lstlast(*a);
	*maxbottom = ptr->value;
	while (ptr->index > (size - 5))
	{
		printf("\033[0;34m" "ptrin=%d, val=%d\n" "\x1B[0m", ptr->index, ptr->value);
		if (*maxbottom < ptr->prev->value)
			*maxbottom = ptr->prev->value;
		printf("\033[0;34m" "maxb=%d\n" "\x1B[0m", *maxbottom);
		ptr = ptr->prev;
	}
}

void sort(t_stack_node **a, t_stack_node **b)
{
	int	maxtop;
	int	maxbottom;
	int	indtop;
	int	indbottom;
	t_stack_node	*ptr;
	
	while (ft_lstsize(*a) > 48)
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
		push_to_b(a,b);	
		if(ft_lstsize(*b) > 1)
		{
			if(ft_lstsize(*b) == 2)
		}
		updateindex(a);
		updateindex(b);
	}

}
