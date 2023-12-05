/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:56:45 by randre            #+#    #+#             */
/*   Updated: 2023/11/29 10:21:34 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*find_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack);
}

long	ft_atol(const char *str)
{
	int		i;
	long	val;

	i = 1;
	val = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			i = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		val *= 10;
		val += *str - '0';
		str++;
	}
	return (val * i);
}

t_stack_node	*find_min(t_stack_node *stack)
{
	t_stack_node	*min;
	
	min = NULL;
	if (!stack)
		return (NULL);
	min = stack;
	while (stack)
	{
		if (stack->nbr < min->nbr)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

t_stack_node	*find_max(t_stack_node *stack)
{
	t_stack_node	*max;
	
	max = NULL;
	if (!stack)
		return (NULL);
	max = stack;
	while (stack)
	{
		if (stack->nbr > max->nbr)
			max = stack;
		stack = stack->next;
	}
	return (max);
}