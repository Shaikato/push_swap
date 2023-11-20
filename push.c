/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:12:54 by randre            #+#    #+#             */
/*   Updated: 2023/11/20 18:24:24 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack_node **head_a, t_stack_node **head_b)
{
	(*head_a)->prev = *head_b;
	(*head_b)->next = *head_a;
	(*head_a)->index++;
	head_a++;
	while ((*head_a)->next)
	{
		(*head_a)->index++;
		head_a++;
	}
	(*head_a)->index++;
	ft_printf("pa\n");
}

void	pb(t_stack_node **head_a, t_stack_node **head_b)
{
	(*head_b)->prev = *head_a;
	(*head_a)->next = *head_b;
	(*head_b)->index++;
	head_b++;
	while ((*head_b)->next)
	{
		(*head_b)->index++;
		head_b++;
	}
	(*head_b)->index++;
	ft_printf("pb\n");
}