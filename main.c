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
		init_stack(&a, argv);
		affiche_list(a);
		printf("\n");
	/*	swap_a(a);
		affiche_list(a);
		printf("\n");
		rotate_nodes_a(&a);
		affiche_list(a);
		printf("\n");
		reverse_rotate_nodes_a(&a);
		affiche_list(a);
		printf("\n");
		printf("affiche pbpbpbrrb\n");*/
		push_to_b(&a, &b);
		push_to_b(&a, &b);
		push_to_b(&a, &b);
		push_to_b(&a, &b);
		affiche_list(b);
		printf("\n");
	//	reverse_rotate_nodes_a(&b);
		affiche_list(a);
		printf("\n");
		rotate_nodes_ab(&a, &b);
		affiche_list(b);
		printf("\n");
		affiche_list(a);
	//	printf("affiche papa\n");
		/*push_to_a(&a, &b);
		push_to_a(&a, &b);
		affiche_list(b);
		printf("\n");
		affiche_list(a);*/

		
	}
	if (argc == 2)
		free_split(argv);
	ft_lstclear(&a);
	//ft_lstclear(&b);
	return (0);

}