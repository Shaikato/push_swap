/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:23:03 by randre            #+#    #+#             */
/*   Updated: 2024/01/08 11:28:33 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_stack_node **a, t_stack_node **b, 
						t_stack_node *cheapest)
{
	while (*a != cheapest->target_node && *b != cheapest)
		rr(a, b);
	update_index(*a);
	update_index(*b);
}

static void	reverse_rotate_both(t_stack_node **a, t_stack_node **b, 
								t_stack_node *cheapest)
{
	while (*a != cheapest->target_node && *b != cheapest)
		rrr(a, b);
	update_index(*a);
	update_index(*b);
}

static void	final_rotate_a(t_stack_node **a, t_stack_node *cheapest)
{
	while (*a != cheapest)
	{
		if (cheapest->above_median)
			ra(a);
		else
			rra(a);
	}
}

static void	final_rotate_b(t_stack_node **b, t_stack_node *cheapest)
{
	while (*b != cheapest)
	{
		if (cheapest->above_median)
			rb(b);
		else
			rrb(b);
	}
}

void	move_nodes(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;

	cheapest = find_cheapest(b);
	if (cheapest->above_median && cheapest->target_node->above_median)
		rotate_both(a, b, cheapest);
	else if (!(cheapest->above_median) 
		&& !(cheapest->target_node->above_median))
		reverse_rotate_both(a, b, cheapest);
	final_rotate_b(b, cheapest);
	final_rotate_a(a, cheapest->target_node);
	pa(a, b);
}
