#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack_node *a;
	t_stack_node *b;	
    (void)argc;

	a = NULL;
	b = NULL;

    if (argc < 2)
        return(0);
    if ( argc == 1 || (argc == 2 && argv[1][0] =='\0'))
        return (0);
    if (argc == 2)
        argv = ft_split(argv[1], ' ');
	if (manage_error(argc, argv));
   
	free(&a);
	return (0);


}