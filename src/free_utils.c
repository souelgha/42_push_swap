/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:12:59 by sonouelg          #+#    #+#             */
/*   Updated: 2024/01/15 15:13:01 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/********** free split*****/
void	free_split(char **argv)
{
	int	count;
	int	i;

	count = 1;
	while (argv[count])
		count++;
	i = 0;
	while (i <= count)
		free(argv[i++]);
	free(argv);
}

/** ******free la list *************/
void	ft_lstclear(t_stack_node **lst)
{
	t_stack_node	*tmp;

	if (!lst)
		return ;
	tmp = NULL;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		free(*lst);
		(*lst) = tmp;
	}
	*lst = NULL;
}
