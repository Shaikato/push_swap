/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:36:15 by randre            #+#    #+#             */
/*   Updated: 2023/11/20 18:23:17 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*head;
	
	if (!*stack || !(*stack)->next)
		return ;
	head = *stack;
	(*stack)->next->prev = NULL;
	(*stack)->next->index = 0;
	stack += 2;
	while((*stack)->next)
	{
		(*stack)->index -= 1;
		head->index++;
		stack++;
	}
	(*stack)->index -= 1;
	head->index++;
	(*stack)->next = head;
	head->prev = *stack;
	head->next = NULL;
}

void	ra(t_stack_node **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack_node **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}