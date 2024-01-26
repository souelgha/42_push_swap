#include "push_swap.h"

/**********tests avec le main des listes *******/
int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	int 	*tab;
	
	a = NULL;
	b = NULL;
	if ( argc == 1 || (argc == 2 && argv[1][0] =='\0'))
        return (0);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if(!manage_error(argv))
	{
		init_stack_a(&a, argv);
		// printf("Sai(%p)\n", &a);
		// affiche_list(a);
		// printf("\n");
		tab = sortab_final(argv, ft_lstsize(a));
		valeur_final_node(&a, tab, ft_lstsize(a));
		printf("size=%d\n", ft_lstsize(a));
		printf( "\033[0;33m" "Satab(%p)\n" "\x1B[0m", &a);
		affiche_list(a);
		printf("\n");
	//	small = smallest(a);
		if (!check_sort(a))
		{
			if(ft_lstsize(a) == 2)
				swap_a(&a);
			else if (ft_lstsize(a) == 3)
				sort_three(&a);
			else if (ft_lstsize(a) == 4 || ft_lstsize(a) == 5)
				sort_uptofive(&a, &b);
			else
				sort(&a, &b);
		}
		printf( "\033[0;31m" "Safin(%p)\n" "\x1B[0m", &a);
		affiche_list(a);	
		printf("Sb(%p)\n", &b);
		affiche_list(b);;
		printf("\n");	
			
	}
	if (argc == 2)
		free_split(argv);
	ft_lstclear(&a);
	return (0);

}