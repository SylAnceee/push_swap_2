/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abreuil <abreuil@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:00:12 by abreuil           #+#    #+#             */
/*   Updated: 2024/12/18 15:25:57 by abreuil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_number;

	biggest_number = find_max(*a);
	if (*a == biggest_number)
		ra(a, false);
	else if((*a) -> next == biggest_number)
		rra(a, false);
	if ((*a) -> nbr > (*a) -> next -> nbr)
		sa(a, false);
}