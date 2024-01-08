/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:12:54 by randre            #+#    #+#             */
/*   Updated: 2024/01/08 11:27:46 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*buff;

	if (!*src)
		return ;
	buff = *src;
	if (*src)
		buff->prev = NULL;
	*src = (*src)->next;
	if (!*dst)
	{
		*dst = buff;
		buff->next = NULL;
	}
	else
	{
		buff->next = *dst;
		(*dst)->prev = buff;
		*dst = buff;
	}
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	pb(t_stack_node **a, t_stack_node **b)
{
	push(b, a);
	ft_printf("pb\n");
}
