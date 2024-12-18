/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abreuil <abreuil@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:13:07 by abreuil           #+#    #+#             */
/*   Updated: 2024/12/18 15:37:02 by abreuil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "ft_printf/ft_printf.h"

# include <stdlib.h>
# include <unistd.h>
# include <limits.h> 
# include <stdbool.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
	struct s_stack_node	*target_node;
}	t_stack_node;

void			free_stack(t_stack_node **stack);
int				error_duplicate(t_stack_node *stack, int n);
int				error_syntax(char *av);
void			free_errors(t_stack_node **stack);
char			**ft_split_diff(char *str, char c);
long			ft_atol(const char *str);
void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			init_nodes_b(t_stack_node *a, t_stack_node *b);
void			current_index(t_stack_node *stack);
void			set_target_a(t_stack_node *a, t_stack_node *b);
void			set_target_b(t_stack_node *a, t_stack_node *b);
void			set_cheapest(t_stack_node *a);
void			cost_analysis(t_stack_node *a, t_stack_node *b);
int				stack_size(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);
void			push(t_stack_node **src, t_stack_node **dst);
void			pa(t_stack_node **a, t_stack_node **b, bool print);
void			pb(t_stack_node **a, t_stack_node **b, bool print);
void			swap(t_stack_node **stack);
void			sa(t_stack_node **a, bool print);
void			sb(t_stack_node **b, bool print);
void			ss(t_stack_node **a, t_stack_node **b, bool print);
void			rotate(t_stack_node **stack);
void			ra(t_stack_node **a, bool print);
void			rb(t_stack_node **b, bool print);
void			rr(t_stack_node **a, t_stack_node **b, bool print);
void			reverse_rotate(t_stack_node **stack);
void			rra(t_stack_node **a, bool print);
void			rrb(t_stack_node **b, bool print);
void			rrr(t_stack_node **a, t_stack_node **b, bool print);
void			sort_stacks(t_stack_node **a, t_stack_node **b);
void			sort_three(t_stack_node **a);
void			move_a_to_b(t_stack_node **a, t_stack_node **b);
void			move_b_to_a(t_stack_node **a, t_stack_node **b);
void			min_to_top(t_stack_node **a);
void			append_node(t_stack_node **stack, int n);
t_stack_node	*get_cheapest(t_stack_node *stack);
void			prep_for_push(t_stack_node **stack, t_stack_node *top,
					char name);
void			rotate_both(t_stack_node **a, t_stack_node **b,
					 t_stack_node *cheapest_node);
void			rev_rotate_both(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest_node);
void			init_stack_a(t_stack_node **a, char **av);
int				main(int ac, char **av);
#endif
