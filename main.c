#include "push_swap.h"

int main(int argc, char **argv)
{
    int     i;    
    char    **tab = NULL;
    (void)argc;

    if (argc < 2)
        return(0);
    if ( argc == 1 || (argc == 2 && argv[1][0] =='\0'))
        return (0);
    if (argc == 2)
        tab = ft_split(argv[1], ' ');
    i = 0;
    while ( tab[i][0] != '\0')
	{
		printf("tab[%d] =%s\n", i, tab[i]); 
        free(tab[i]);
		i++;
	}
	free(tab);
	return (0);


}