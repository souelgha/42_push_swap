#include "push_swap.h"

/*fonction error de syntax . return 1 si error*/
int	error_syntax(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '+' && str[i] != '-')			
			return(1);
		i++;
	}
	return (0);
}

/********gestion des doublons. return 1 si error****/
int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		else
			i++;
	}
	return (0);
}

int	error_duplicate(int i, char **argv)
{
	int	j;

	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if ((ft_strcmp(argv[i], argv[j]) != 0))
				j++;
			else
			{
				return (1);
				break;
			}
		}
		i++;
	}
	return (0);
}
/*************print des erreurs***************/
void	print_error(void)
{
	write(2, "Error\n", 6);
}
/************* management des erreurs***************/
void manage_error(int i, char **argv)
{
	long int	nb;

	nb = 0;
    if (error_duplicate(i, argv))
        print_error();   
    while (argv[i])
    {
	    if (error_syntax(argv[i]))
		{
            print_error();
			break;
		}
		nb = ft_atoi(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
		{
			print_error();
			break;
		}
        i++;
    }
}
int	main(int argc, char **argv)
{
	(void)argc;
    int i;
	if ( argc == 1 || (argc == 2 && argv[1][0] =='\0'))
        return (0);
	if (argc == 2) 
        i = 0;
    else
        i = 1;
    if (argc == 2)
		argv = ft_split(argv[1], ' ');   
	manage_error(i, argv);
	return (0);

}
