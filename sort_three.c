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

void	sort_three(t_stack_node **a)
{
	t_stack_node	*last;

	last = find_last(*a);
	if ((*a)->nbr > (*a)->next->nbr && (*a)->nbr > last->nbr)
		ra(a);
	else if ((*a)->next->nbr > (*a)->nbr && (*a)->next->nbr > last->nbr)
		rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
}