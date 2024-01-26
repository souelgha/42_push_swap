/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:39:58 by sonouelg          #+#    #+#             */
/*   Updated: 2024/01/26 11:54:27 by sonouelg         ###   ########.fr       */
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

typedef struct s_stack
{
	int				value;
	int				index;
	int				cost;				
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/**********fonctions libft******/

char			**ft_split(char const *s, char c);
size_t			ft_strlen(const char *str);
long int		ft_atoi(const char *str);

/**********gestion des errors****/
void			ft_lstclear(t_stack **lst);
int				error_syntax(char *str);
int				error_duplicate(char **argv);
void			print_error(void);
int				manage_error(char **argv);

/*************listes**************/
t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_lstnew_node(char *str, int index);
void			ft_lstclear(t_stack **lst);
int				ft_lstsize(t_stack *lst);
void			ft_lstadd_back(t_stack **lst, t_stack *new_node);
void			ft_lstadd_front(t_stack **lst, t_stack *new_node);
void			ft_add_front_node(t_stack **lst, t_stack *new_node);
void			init_stack_a(t_stack **a, char **argv);
void			affiche_list(t_stack *lst);
void			affiche_status(t_stack **lst);

/*************free de memoire******/
void			free_split(char **argv);

/*************commandes sur les piles*****/
void			swap(t_stack **stack);
void			swap_a(t_stack **stack);
void			swap_b(t_stack **stack);
void			swap_ss(t_stack **stack_a, t_stack **stack_b);
void			rotate_nodes(t_stack **stack);
void			rotate_nodes_a(t_stack **stack);
void			rotate_nodes_b(t_stack **stack);
void			rotate_nodes_ab(t_stack **stack_a, t_stack **stack_b);
void			reverse_rotate_nodes(t_stack **stack);
void			reverse_rotate_nodes_a(t_stack **stack);
void			reverse_rotate_nodes_b(t_stack **stack);
void			reverse_rotate_nodes_ab(t_stack **a, t_stack **b);
void			push_to_b(t_stack **stack_a, t_stack **stack_b);
void			push_to_a(t_stack **stack_a, t_stack **stack_b);

/*********sort fonctions*******************/
void			sort_three(t_stack **a);
int				cmpn(t_stack *a, t_stack *b);
int				check_sort(t_stack *stack_a);
void			quick_sort(t_stack **stack_a);
int				*sortab_final(char **argv, int size);
int				*create_tab(char **argv, int size);
void			indice_final_node(t_stack **a, int *tab, int size);
void			valeur_final_node(t_stack **a, int *tab, int size);
void			ft_swap(int *a, int *b);
void			sort_uptofive(t_stack **a, t_stack **b);
void 			sort(t_stack **a, t_stack **b);
int				maxi(t_stack *a);
int				mini(t_stack *a);

/*********utils sort fonctions*******************/
void			case_rotate_a(t_stack **a, t_stack **b);
void			case_rev_rotate_a(t_stack **a);
void			case_inrev_rotate_a(t_stack **a, t_stack **b);
void			sizeuptothree(t_stack **a, t_stack **b);
void			slt(t_stack **a, t_stack **b, int n, t_stack *p);
void			firstcase(t_stack **a, t_stack **b);
void			secondcase(t_stack **a, t_stack **b);
void			thirdcase(t_stack **a, t_stack **b);
void			forthcase(t_stack **a, t_stack **b);
void			sortend(t_stack **a);
void			updateindex(t_stack **a);
void			find_max(t_stack **a, int *maxtop, int *maxbottom);
int 			findpos(t_stack **a, t_stack **b);
void 			target(t_stack *a, t_stack *b);
t_stack 		*smallest(t_stack *a);
void 			cost(t_stack *a, t_stack *b);

#endif