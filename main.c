#include "push_swap.h"

/**********tests avec le main des listes *******/
int main(int argc, char **argv)
{
	t_stack_node *a;
	t_stack_node *b;
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
		printf("Sa(%p)\n", &a);
		affiche_list(a);
		printf("\n");
		tab = sortab_final(argv, ft_lstsize(a));
		indice_final_node(&a, tab, ft_lstsize(a));
	//	printf("size=%d\n", ft_lstsize(a));
	//	if (!check_sort(a))
		// {
		// 	if(ft_lstsize(a) == 2)
		// 		swap_a(&a);
		// 	else if (ft_lstsize(a) == 3)
		// 		sort_three(&a);
		// 	// else
		// 	// 	quick_sort(&a);
		// }
	//	printf("size=%d\n", ft_lstsize(a));
		printf("Sa(%p)\n", &a);
		affiche_list(a);
		printf("\n");
	//	affiche_list(b);
		// swap_a(&a);
		// printf("Sa(%p)\n", a);
		// affiche_list(a);
		// printf("\n");
		// reverse_rotate_nodes_a(&a);
		// printf("Sa(%p)\n", a);
		// affiche_list(a);
		// printf("\n");
		// sort_two(a);
		// printf("sort two Sa(%p)\n", &a);
		// affiche_list(a);
		// printf("\n");
		
	}
	if (argc == 2)
		free_split(argv);
	ft_lstclear(&a);
//	free(tab);
//	ft_lstclear(&b);
	return (0);

}