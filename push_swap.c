/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:08:15 by randre            #+#    #+#             */
/*   Updated: 2023/11/29 11:44:02 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_two(int argc, char **argv, t_stack_node **a)
{
	int	i;

	i = -1;
	if (argc == 2 && !argv[1][0])
		exit (0);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (argv[0][0] == '-')
			++i;
		while (argv[0][++i] != '\0')
			if (!ft_isdigit(argv[0][i]))
			{
				write(2, "Error\n", 6);
				exit (0);
			}
		if (!argv[1] && !invalid_number(argv[0]) && !((ft_atol(argv[0]) > INT_MAX || ft_atol(argv[0]) < INT_MIN)))
			exit (0);
		else if (ft_atol(argv[0]) > INT_MAX || ft_atol(argv[0]) < INT_MIN)
		{
			write(2, "Error\n", 6);
			exit (0);
		}
		init_stack(a, argv, 1);
	}
	else
		init_stack(a, argv + 1, 0);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
	{
		write(2, "Error\n", 6);
		exit (0);
	}
	handle_two(argc, argv, &a);
	if (!is_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort(&a, &b);
	}
	free_stack(&a);
	return (0);
}