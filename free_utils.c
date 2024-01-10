#include "push_swap.h"

/********** free split*****/
void	free_split(char **argv)
{
	int	count;
	int	i;

	count = 1;
	while (argv[count])
		count++;
	i = 0;
	while (i <= count)
		free(argv[i++]);
	free(argv);
}