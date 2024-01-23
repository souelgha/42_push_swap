/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonia <sonia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:39:58 by sonouelg          #+#    #+#             */
/*   Updated: 2024/01/22 11:56:56 by sonia            ###   ########.fr       */
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
	int						index;
	int						index_final;
	struct s_stack_node		*target_node;
	struct s_stack_node		*next;
	struct s_stack_node		*prev;
}	t_stack_node;

/**********fonctions libft******/

char			**ft_split(char const *s, char c);
size_t			ft_strlen(const char *str);
long int		ft_atoi(const char *str);

/**********gestion des errors****/
void			ft_lstclear(t_stack_node **lst);
int				error_syntax(char *str);
int				error_duplicate(char **argv);
void			print_error(void);
int				manage_error(char **argv);

/*************listes**************/
t_stack_node	*ft_lstlast(t_stack_node *lst);
t_stack_node	*ft_lstnew_node(char *str, int index);
void			ft_lstclear(t_stack_node **lst);
int				ft_lstsize(t_stack_node *lst);
void			ft_lstadd_back(t_stack_node **lst, t_stack_node *new_node);
void			ft_lstadd_front(t_stack_node **lst, t_stack_node *new_node);
void			ft_add_front_node(t_stack_node **lst, t_stack_node *new_node);
void			init_stack_a(t_stack_node **a, char **argv);
void			affiche_list(t_stack_node *lst);
void			affiche_status(t_stack_node **lst);

/*************free de memoire******/
void			free_split(char **argv);

/*************commandes sur les piles*****/
void			swap(t_stack_node **stack);
void			swap_a(t_stack_node **stack);
void			swap_b(t_stack_node **stack);
void			swap_ss(t_stack_node **stack_a, t_stack_node **stack_b);
void			rotate_nodes(t_stack_node **stack);
void			rotate_nodes_a(t_stack_node **stack);
void			rotate_nodes_b(t_stack_node **stack);
void			rotate_nodes_ab(t_stack_node **stack_a, t_stack_node **stack_b);
void			reverse_rotate_nodes(t_stack_node **stack);
void			reverse_rotate_nodes_a(t_stack_node **stack);
void			reverse_rotate_nodes_b(t_stack_node **stack);
void			reverse_rotate_nodes_ab(t_stack_node **a, t_stack_node **b);
void			push_to_b(t_stack_node **stack_a, t_stack_node **stack_b);
void			push_to_a(t_stack_node **stack_a, t_stack_node **stack_b);

/*********sort fonctions*******************/
void			sort_three(t_stack_node **a);
int				cmpn(t_stack_node *a, t_stack_node *b);
int				check_sort(t_stack_node *stack_a);
void			quick_sort(t_stack_node **stack_a);
int				*sortab_final(char **argv, int size);
int				*create_tab(char **argv, int size);
void			indice_final_node(t_stack_node **a, int *tab, int size);
void			valeur_final_node(t_stack_node **a, int *tab, int size);
void			ft_swap(int *a, int *b);
void			sort_uptofive(t_stack_node **a, t_stack_node **b);
int				abs(int n);

#endif