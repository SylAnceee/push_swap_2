/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                  			:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abreuil <abreuil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:12:33 by abreuil           #+#    #+#             */
/*   Updated: 2024/12/06 19:18:02 by abreuil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*tmp;

	if (!*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	tmp->prev = NULL;
	if (!*a)
	{
		*a = tmp;
		tmp->next = NULL;
	}
	else
	{
		tmp->next = *a;
		(*a)->prev = tmp; // tmp is the new top of the stack a
		*a = tmp;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool print) //push top of b to a
{
	push(b, a);
	if (!print)
		ft_printf("pa\n");
}
void	pb(t_stack_node **a, t_stack_node **b, bool print)//push top of a to b
{
	push( a, b);
	if (!print)
		ft_printf("pb\n");
}
