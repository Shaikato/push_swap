/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 22:35:50 by randre            #+#    #+#             */
/*   Updated: 2023/11/20 22:35:50 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*last;
	t_stack_node	*new;

	last = find_last(*stack);
	new = malloc(sizeof(t_stack_node));
	if (last == NULL)
	{
		new->nbr = n;
		new->index = 0;
		new->prev = NULL;
		new->next = NULL;
		*stack = new;
	}
	else
	{
		new->nbr = n;
		new->index = last->index + 1;
		new->prev = last;
		new->next = NULL;
		last->next = new;
	}
}

void	init_stack(t_stack_node **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_synthax(argv[i]))
			errors_free(a);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			errors_free(a);
		append_node(a, (int)n);
		i++;
	}
}