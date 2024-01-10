/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:03:10 by sonouelg          #+#    #+#             */
/*   Updated: 2024/01/10 15:11:15 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*************print des erreurs***************/
void	print_error(void)
{
	write(2, "Error\n", 6);
}

/*fonction error de syntax . return 1 si error*/
int	error_syntax(char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '+' && str[i] != '-')
		{
			return (1);
			break ;
		}
		i++;
	}
	return (0);
}

/********gestion des doublons. return 1 si error****/
int	error_duplicate(char **argv)
{
	int	j;
	int	i;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if ((ft_atoi(argv[i]) != ft_atoi(argv[j])))
				j++;
			else
			{
				return (1);
				break ;
			}
		}
		i++;
	}
	return (0);
}

/*******overflow int *********/
int	check_int_arg(char **argv)
{
	int			i;
	int			j;
	long int	nb;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
			j++;
		if (j > 11)
			return (1);
		nb = ft_atoi(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

/************* management des erreurs***************/
int	manage_error(char **argv)
{
	int	i;

	if (error_duplicate(argv))
	{
		print_error();
		return (1);
	}
	else if (check_int_arg(argv))
	{
		print_error();
		return (1);
	}
	i = 1;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
		{
			print_error();
			return (1);
		}
		i++;
	}
	return (0);
}
