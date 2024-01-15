#include "push_swap.h"

/**********tests avec le main des listes *******/
int main(int argc, char **argv)
{
	t_stack_node *a;
	t_stack_node *b;
	
    (void)argc;

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
	//	sort_three_args(a);
	//	printf("b");
	//	affiche_list(b);
		printf("Sa(%p)\n", &a);
		swap_a(a);
		affiche_list(a);
		printf("\n");
		rotate_nodes_a(&a);
		printf("Sa(%p)\n", &a);
		affiche_list(a);
		printf("\n");
		reverse_rotate_nodes_a(&a);
		printf("Sa(%p)\n", &a);
		affiche_list(a);
		printf("\n");
		push_to_b(&a, &b);
		push_to_b(&a, &b);
		push_to_b(&a, &b);
		push_to_b(&a, &b);
		push_to_b(&a, &b);
		push_to_b(&a, &b);
		push_to_b(&a, &b);
		push_to_b(&a, &b);
		push_to_a(&a, &b);
		push_to_a(&a, &b);
		push_to_a(&a, &b);	
		push_to_a(&a, &b);
		printf("Sa(%p)\n", &a);
		affiche_list(a);
		printf("Sb(%p)\n", &b);
		affiche_list(b);
		printf("\n");
		swap_ss(a, b);
		printf("Sa : \n");
		affiche_list(a);
		printf("Sb : \n");
		affiche_list(b);		
		printf("\n");
		rotate_nodes_ab(&a, &b);
		printf("Sa : \n");
		affiche_list(a);
		printf("Sb : \n");
		affiche_list(b);		
		printf("\n");
		reverse_rotate_nodes_ab(&a, &b);
		printf("Sa : \n");
		affiche_list(a);
		printf("Sb : \n");
		affiche_list(b);		
		printf("\n");
	//	printf("affiche papa\n");
	//push_to_a(&a, &b);
	//	push_to_a(&a, &b);
	//	affiche_list(b);
	//	printf("\n");
	//	affiche_list(a);
//
		
	}
	if (argc == 2)
		free_split(argv);
	ft_lstclear(&a);
	ft_lstclear(&b);
	return (0);

}