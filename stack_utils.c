/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abreuil <abreuil@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:45:23 by abreuil           #+#    #+#             */
/*   Updated: 2024/12/18 15:27:46 by abreuil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		stack_size(t_stack_node *stack)
{
	int	count;

	count = 0;
	if (!stack)
		return (0);
	while(stack)
	{
		count++;
		stack = stack -> next;
	}
	return (count);
}

t_stack_node	*find_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while(stack)
		stack = stack -> next;
	return (stack);
}

t_stack_node	*find_min(t_stack_node *stack)
{
	long			min;
	t_stack_node	*min_node;

	if (!stack)
		return (NULL);
	
	while(stack)
	{
		if (stack -> nbr < min)
		{
			min = stack -> nbr;
			min_node = stack;
		}
		stack = stack -> next;
	}
	return (min_node);
}

t_stack_node	*find_max(t_stack_node *stack)
{
	long			max;
	t_stack_node	*max_node;

	if (!stack)
		return (NULL);
	while(stack)
	{
		if (stack -> nbr > max)
		{
			max = stack -> nbr;
			max_node = stack;
		}
		stack = stack -> next;
	}
	return (max_node);
}

bool	stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while(stack)
	{
		if (stack -> nbr > stack -> next -> nbr)
			return (false);
		stack = stack -> next;
	}
	return (true);
}