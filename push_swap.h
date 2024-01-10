/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:39:58 by sonouelg          #+#    #+#             */
/*   Updated: 2024/01/10 15:07:42 by sonouelg         ###   ########.fr       */
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
	int						value;
	int 					index;

	struct	s_stack_node	*target_node;
	struct 	s_stack_node	*next;
	struct  s_stack_node 	*prev;
}	t_stack_node;

/**********fonctions libft******/

char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
long int		ft_atoi(const char *str);

/**********gestion des errors****/
void	ft_lstclear(t_stack_node **lst);
int		error_syntax(char *str);
int		error_duplicate(char **argv);
void	print_error(void);
int		manage_error(char **argv);

/*************listes************/
t_stack_node	*ft_lstnew(int value);
t_stack_node	*ft_lstlast(t_stack_node *lst);
void			ft_lstclear(t_stack_node **lst);

/*************free de memoire******/
void	free_split(char **argv);



#endif