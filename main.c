#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack_node *a;
	t_stack_node *b;
	int			i;
    (void)argc;

	a = NULL;
	b = NULL;

	if ( argc == 1 || (argc == 2 && argv[1][0] =='\0'))
        return (0);
	if (argc == 2)
	{
		i = 0;
		argv = ft_split(argv[1], ' ');
	}         
    else
        i = 1; 
	manage_error(i, argv);
	init_stack(&a, argv);
   
	free(&a);
	return (0);
/**** mettre une condition sur argc ==2 pour free le split****/

}