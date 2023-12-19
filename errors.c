/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 22:39:41 by randre            #+#    #+#             */
/*   Updated: 2023/11/20 22:39:41 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_synthax(char *str)
{
	if (!ft_atol(str) && *str != '0')
		return (1);
	return (0);
}

int	check_limit(const char *str)
{
	long long int	result;
	int				i;
	int				sign;

	result = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - '0');
	result = result * sign;
	if (result > INT_MAX || result < INT_MIN)
		return (1);
	else
		return (0);
}

int	invalid_number(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '-' && i != 0)
			return (1);
		if (s[i] == '-' && !(s[i + 1] >= '0' && s[i + 1] <= '9'))
			return (1);
		if ((s[i] == '0' && i == 0 && s[i + 1] != '\0') || (s[i] == '0' && s[i
					- 1] == '-'))
			return (1);
		if (s[i] == '+')
			return (1);
		i++;
	}
	return (0);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	errors_free(t_stack_node **a, char **s, int mal_bool)
{
	int	i;

	i = -1;
	free_stack(a);
	if (mal_bool)
		while (s[++i] != NULL)
			free(s[i]);
	write(2, "Error\n", 6);
	exit(0);
}