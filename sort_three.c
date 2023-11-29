/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 22:15:08 by randre            #+#    #+#             */
/*   Updated: 2023/11/29 10:35:53 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	last_opt_handler(t_stack_node **a, t_stack_node *max)
{
	if (max->index == 0)
	{
		sa(a);
		rra(a);
	}
	else
		rra(a);
}

void	sort_three(t_stack_node **a)
{
	t_stack_node	*min;
	t_stack_node	*max;
	
	min = find_min(*a);
	max = find_max(*a);
	if (min->index == 0)
	{
		if (max->index == 2)
			return ;
		else
		{
			sa(a);
			ra(a);
		}
	}
	else if (min->index == 1)
	{
		if (max->index == 2)
			sa(a);
		else
			ra(a);
	}
	else
		last_opt_handler(a, max);
}