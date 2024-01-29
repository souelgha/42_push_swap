/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:56:04 by sonouelg          #+#    #+#             */
/*   Updated: 2024/01/29 15:01:14 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_sort(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) == 2)
		swap_a(a);
	else if (ft_lstsize(*a) == 3)
		sort_three(a);
	else
		sort(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (0);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (!manage_error(argv))
	{
		init_stack_a(&a, argv);
		if (!check_sort(a))
			apply_sort(&a, &b);
	}
	if (argc == 2)
		free_split(argv);
	ft_lstclear(&a);
	return (0);
}
