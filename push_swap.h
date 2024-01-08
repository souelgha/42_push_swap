/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonia <sonia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:39:58 by sonouelg          #+#    #+#             */
/*   Updated: 2024/01/08 17:32:47 by sonia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

/********structure d un node */

typedef struct s_stack_node
{
	int		value;
	int 	index;

	struct	s_stack_node	*target_node;
	struct 	s_stack_node	*next;
	struct  s_stack_node 	*prev;
}	t_stack_node;

/**********fonctions libft******/

char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
int	ft_atoi(const char *str);

/**********gestion des errors****/
int error_syntax(char *str);
void	ft_lstclear(t_stack_node **lst);





#endif