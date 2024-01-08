#include "push_swap.h"
/** free la list */
void	ft_lstclear(t_stack_node **lst)
{
	t_stack_node	*tmp;

	if (!lst)
		return ;
	tmp = NULL;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		free(*lst);
		(*lst) = tmp;
	}
	*lst = NULL;
}

/*fonction error de syntax . return 1 si error*/
int error_syntax(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '+' && str[i] != '-')			
			return(1);
		i++;
	}
	return(0);
}

/********gestion des doublons ****/
int error_duplicate(char **argv)
{
	
}


/*
int main(int argc, char **argv)
{
	int	j;
	(void)argc;

	j = error_syntax(argv[1]);	
	printf("%d. argv[1]=%s\n", j, argv[1]);
	return (0);

}*/


