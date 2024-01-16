#include "push_swap.h"

int	check_sort(t_stack_node *stack_a)
{
	t_stack_node *ptr;

	if (!stack_a)
		return (-1);
	ptr = stack_a;
	while (ptr->next != NULL)
	{
		if((ptr->value) > (ptr->next->value))
			return(0);
		ptr= ptr->next;						
	}
	return (1);
}
/**** size = taille de la liste avec lstsize*/

int	*sortab_final(char **argv, int size)
{
	int	i;
	int j;
	int	*tab;
	int	min;

	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < size)
	{
		tab[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	i = 0;
	while (i < size)
	{
		j = i + 1;
		printf("i=%d, j=%d\n", i, j);
		while (j < size)
		{
			if (tab[j] < tab[i])
			{
				min = tab[j];
				tab[j] = tab[i];
				tab[i] = min;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < size)
	{
		printf("tab[%d]=%d \t", i, tab[i]);
		i++;
	}
	return (tab);
}

void	indice_final_node(t_stack_node **a, int *tab, int size)
{
	t_stack_node *ptr;
	int	i;

	ptr = *a;
	while (ptr->index < size)
	{
		i = 0;
		while (i < size)
		{
			if (ptr->value == tab[i])
			{
				ptr->index_final = i;
				break;
			}
			i++;
		}
		ptr = ptr->next;		
	}
	ptr=ft_lstlast(*a);
	while(i < size)
	{
		if(ptr->value == tab[i])
			ptr->index_final = i;
		i++;
	}


	

}
