/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abreuil <abreuil@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:56:05 by abreuil           #+#    #+#             */
/*   Updated: 2024/12/18 15:24:46 by abreuil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*target;
	t_stack_node	*current_a;
	long			best_match_index;

	while (a)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a -> nbr > b -> nbr && current_a -> nbr < best_match_index)
			{
				target = current_a;
				best_match_index = current_a -> nbr;
			}
			current_a = current_a -> next;
		}
		if (best_match_index == LONG_MAX)
			target = find_min(a);
		else
			b -> target_node = target;
		b = b -> next;
	}
}

void	init_nodes_b(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}