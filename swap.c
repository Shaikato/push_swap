/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:14:41 by randre            #+#    #+#             */
/*   Updated: 2023/11/20 18:36:48 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack_node **stack)
{	
	if(!*stack || !(*stack)->next)
		return ;
	(*stack)->index = 1;
	*stack = (*stack)->next;
	(*stack)->index = 0;
	(*stack)->prev->prev = *stack;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->prev->next = (*stack)->next;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

void	sa(t_stack_node **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack_node **b)
{
	swap(b);
	ft_printf("sa\n");
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}