/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:56:10 by randre            #+#    #+#             */
/*   Updated: 2024/01/08 11:29:21 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	is_sorted(t_stack_node *a)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->nbr < a->next->nbr)
			a = a->next;
		else
			return (0);
	}
	return (1);
}

int	stack_len(t_stack_node *a)
{
	int	i;

	if (!a)
		return (0);
	i = 0;
	while (a->next)
	{
		i++;
		a = a->next;
	}
	i++;
	return (i);
}
