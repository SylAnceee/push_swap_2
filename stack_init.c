/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abreuil <abreuil@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:18:37 by abreuil           #+#    #+#             */
/*   Updated: 2024/12/18 15:47:41 by abreuil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long		ft_atol(const char *str)
{
	long		nb;
	int			sign;

	nb = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + *str - '0';
		str++;
	}
	return (nb * sign);
}
void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return;
	node -> next = NULL;
	node -> nbr = n;
	node -> cheapest = 0;
	if (!(*stack))
	{
		*stack = node;
		node -> prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node -> next = node;
		node -> prev = last_node;
	}
}

void	init_stack_a(t_stack_node **a, char **av)
{
	int		i;
	long	value;

	i = 0;
	while (av[i])
	{
		if (error_syntax(*av))
			free_errors(a);
		value = ft_atol(av[i]);
		if (error_duplicate(*a, value))
			free_errors(a);
		append_node(a, value);
		i++;
	}
}

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while(stack)
	{
		if (stack -> cheapest)
			return (stack);
		stack = stack -> next;
	}
	return (NULL);
}

void	prep_for_push(t_stack_node **stack, t_stack_node *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node -> above_median)
				ra(stack, false);
			else
			rra(stack, false);
		}	
		else if (stack_name == 'b')
		{
			if (top_node -> above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}