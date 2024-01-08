/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 22:35:50 by randre            #+#    #+#             */
/*   Updated: 2024/01/08 11:27:04 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	check_empty(char **s)
{
	if (!s[0])
	{
		exit(0);
	}
}

void	handle_duplicates(char **s, t_stack_node **a, int mal_bool)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	check_empty(s);
	while (s[i] != NULL)
	{
		while (s[j] != NULL)
		{
			if (ft_strncmp(s[i], s[j], INT_MAX) == 0)
				errors_free(a, s, mal_bool);
			j++;
		}
		i++;
		j = i + 1;
	}
}

void	handle_numeric(char **s, t_stack_node **a, int mal_bool)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != NULL)
	{
		if (invalid_number(s[i]))
			errors_free(a, s, mal_bool);
		while (s[i][j] != '\0')
		{
			if ((!ft_isdigit(s[i][j]) && (j != 0 && s[i][j] != '-'))
				|| check_limit(s[i])
				|| ft_strlen(s[i]) >= 20)
				errors_free(a, s, mal_bool);
			j++;
		}
		j = 0;
		i++;
	}
}

void	init_stack(t_stack_node **a, char **argv, int mal_bool)
{
	long	n;
	int		i;

	i = 0;
	if (!argv || !argv[0])
		errors_free(a, argv, mal_bool);
	while (argv[i])
	{
		if (error_synthax(argv[i]))
			errors_free(a, argv, mal_bool);
		handle_duplicates(argv, a, mal_bool);
		handle_numeric(argv, a, mal_bool);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			errors_free(a, argv, mal_bool);
		append_node(a, (int)n);
		i++;
	}
}
