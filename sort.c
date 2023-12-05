/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:23:45 by randre            #+#    #+#             */
/*   Updated: 2023/11/29 12:35:14 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*match;
	t_stack_node	*buff_a;
	long			match_val;

	while (b)
	{
		match_val = LONG_MAX;
		buff_a = a;
		while (buff_a)
		{
			if (buff_a->nbr > b->nbr && buff_a->nbr < match_val)
			{
				match_val = buff_a->nbr;
				match = buff_a;
			}
			buff_a = buff_a->next;
		}
		if (match_val == LONG_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = match;
		b = b->next;
	}
}

void	sort(t_stack_node **a, t_stack_node **b)
{
	while(stack_len(*a) != 3)
		pb(a, b);
	sort_three(a);
	target_node(*a, *b);
	
}