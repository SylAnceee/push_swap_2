/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abreuil <abreuil@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:40:49 by abreuil           #+#    #+#             */
/*   Updated: 2024/12/18 16:41:38 by abreuil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_stack_node *stack)
{
	int		i;
	int		median;

	i = 0;
	if (!stack)
		return;
	median = stack_size(stack) / 2;
	while (stack)
	{
		stack -> index = i;
		if (i <= median)
		{
			stack -> above_median = true;
		}
		else
			stack -> above_median = false;
		stack = stack -> next;
		i++;
	}
}

void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*target;
	t_stack_node	*current_b;
	long			best_match_index;

	while (a)
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b -> nbr < a -> nbr && current_b -> nbr > best_match_index)
			{
				target = current_b;
				best_match_index = current_b -> nbr;
			}
		current_b = current_b -> next;
		}
		if (best_match_index == LONG_MIN)
			target = find_max(b);
		else
			a -> target_node = target;
		a = a -> next;
	}
}

void	cost_analysis_a(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_size(a); 
	len_b = stack_size(b);
	while(a)
	{
		a -> push_cost = a -> index;
		if (!(a -> above_median))
			a -> push_cost = len_a - (a -> index);
		if (a -> above_median)
			a -> push_cost += a -> target_node -> index;
		else
			a -> push_cost += len_b - (a -> target_node -> index);
		a = a -> next;
	}
}

void	set_cheapest(t_stack_node *stack)
{
	long			cheapest_value;
	t_stack_node	*cheapest_node;

	cheapest_value = LONG_MAX;
	
	if (!stack)
		return;
	while (stack)
	{
		if (stack -> push_cost < cheapest_value)
		{
			cheapest_value = stack -> push_cost;
			cheapest_node = stack;
		}
		stack = stack -> next;
	}
	cheapest_node -> cheapest = true;
}
void	init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}