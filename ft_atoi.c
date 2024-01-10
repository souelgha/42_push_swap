/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 11:03:17 by sonouelg          #+#    #+#             */
/*   Updated: 2024/01/10 12:22:46 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

long int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	long int	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}	
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	//printf("i int atoi =%d\n", i);
	return (nb * sign);
}

