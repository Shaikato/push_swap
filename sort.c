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

t_stack_node	*find_cheapest(t_stack_node **b)
{
	t_stack_node	*tick_b;
	t_stack_node	*cheapest;

	tick_b = *b;
	cheapest = tick_b;
	while (tick_b)
	{
		if (tick_b->cost < cheapest->cost)
			cheapest = tick_b;
		tick_b = tick_b->next;
	}
	return (cheapest);
}

static void	set_cost(t_stack_node *a, t_stack_node *b)
{
	int				len_a;
	int				len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->cost = b->index;
		if (!(b->above_median))
			b->cost = len_b - (b->index);
		if (b->target_node->above_median)
			b->cost += b->target_node->index;
		else
			b->cost += len_a - b->target_node->index;
		b = b->next;
	}
}

static void	target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*buff_a;
	long			match_val;
	t_stack_node	*match;

	while (b)
	{
		match_val = LONG_MAX;
		buff_a = a;
		while (buff_a)
		{
			if (buff_a->nbr > b->nbr && buff_a->nbr < match_val)
			{
				match_val = (long)buff_a->nbr;
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
	t_stack_node	*smallest;

	while(stack_len(*a) != 3)
		pb(a, b);
	update_index(*a);
	update_index(*b);
	sort_three(a);
	while (*b)
	{
		update_index(*a);
		update_index(*b);
		target_node(*a, *b);
		set_cost(*a, *b);
		move_nodes(a, b);
	}
	smallest = find_min(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ra(a);
	else
		while (*a != smallest)
			rra(a);
}