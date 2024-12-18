/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abreuil <abreuil@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:09:12 by abreuil           #+#    #+#             */
/*   Updated: 2024/12/18 14:46:21 by abreuil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;

	if (!stack)
		return;
	while(stack)
	{
		tmp = (*stack) -> next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

int		error_duplicate(t_stack_node *stack, int n)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack -> nbr == n)
			return (1);
		stack = stack -> next;
	}
	return (0);
}

int		error_syntax(char *av)
{
	if (!(*av == '+' || *av == '-' || (*av >= '0' && *av <= '9')))
		return (1);
	if (*av == '+' || (*av == '-' && av[1] >= '0' && av[1] <= '9'))
		return (1);
	while (*++av)
	{
		if (!(*av = '0'&& *av <= '9'))
			return (1);
	}
	return (0);
}

void	free_errors(t_stack_node **stack)
{
	free_stack(stack);
	ft_printf("ERROR\n");
	return ;
}