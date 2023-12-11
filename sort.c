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
	while (b)
	{
		if ((*b)->cheapest == true)
			return (*b);
		*b = (*b)->next;
	}
	return (NULL);
}

static void	set_cost(t_stack_node *a, t_stack_node *b)
{
	int				len_a;
	int				len_b;
	t_stack_node	*cheapest;

	len_a = stack_len(a);
	len_b = stack_len(b);
	cheapest = b;
	b->cheapest = true;
	while (b)
	{
		b->cost = b->index;
		if (!(b->above_median))
			b->cost = len_b - (b->index);
		if (b->target_node->above_median)
			b->cost += b->target_node->index;
		else
			b->cost += len_a - b->target_node->index;
		if (cheapest->cost > b->cost)
		{
			cheapest->cheapest = false;
			cheapest = b;
			cheapest->cheapest = true;
		}
		b = b->next;
	}
}

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
	update_index(*a);
	sort_three(a);
	while (stack_len(*b) != 0)
	{
		update_index(*a);
		update_index(*b);
		target_node(*a, *b);
		set_cost(*a, *b);
		move_nodes(a, b);
	}
}