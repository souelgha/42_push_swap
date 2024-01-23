/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_tab_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonia <sonia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:58:03 by sonouelg          #+#    #+#             */
/*   Updated: 2024/01/22 11:56:56 by sonia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/****verifie si la pile est deja triee ********/
int	check_sort(t_stack_node *stack_a)
{
	t_stack_node	*ptr;

	if (!stack_a)
		return (-1);
	ptr = stack_a;
	while (ptr->next != NULL)
	{
		if ((ptr->value) > (ptr->next->value))
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

/*********swap de 2 nombres*********************/
void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a ;
	*a = *b;
	*b = c;
}

/*****creation du tableau avec les nombres ****/
int	*create_tab(char **argv, int size)
{
	int	i;
	int	*tab;

	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < size)
	{
		tab[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (tab);
}

/***tri des nombres dans un tableau temporaire******/
int	*sortab_final(char **argv, int size)
{
	int	i;
	int	j;
	int	*tab;

	tab = create_tab(argv, size);
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[j] < tab[i])
				ft_swap(&tab[j], &tab[i]);
			j++;
		}
		i++;
	}
	return (tab);
}

/****ajout de l indice final dans le node pour utiliser pour le tri****/
/*void	indice_final_node(t_stack_node **a, int *tab, int size)
{
	t_stack_node	*ptr;
	int				i;

	ptr = *a;
	while (ptr->index <= size)
	{
		i = 0;
		while (i < size)
		{
			if (ptr->value == tab[i])
			{
				ptr->index_final = i;
				break ;
			}
			i++;
		}
		if (ptr == ft_lstlast(*a))
			break ;
		ptr = ptr->next;
	}
	free(tab);
}*/
/****modif des valeurs du tableau dans le node pour utiliser pour le tri****/
void	valeur_final_node(t_stack_node **a, int *tab, int size)
{
	t_stack_node	*ptr;
	int				i;

	ptr = *a;
	while (ptr->index <= size)
	{
		i = 0;
		while (i < size)
		{
			if (ptr->value == tab[i])
			{
				ptr->value = i;
				break ;
			}
			i++;
		}
		if (ptr == ft_lstlast(*a))
			break ;
		ptr = ptr->next;
	}
	free(tab);
}