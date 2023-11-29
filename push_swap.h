/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:06:25 by randre            #+#    #+#             */
/*   Updated: 2023/11/29 10:21:54 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

/*---------------------------Operations--------------------------*/

/*				SWAP			*/
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);

/*				ROTATE			*/
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);

/*			REVERSE ROTATE		*/
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);

/*				PUSH			*/
void			pa(t_stack_node **head_a, t_stack_node **head_b);
void			pb(t_stack_node **head_a, t_stack_node **head_b);

/*---------------------------------------------------------------*/

// Utils

t_stack_node	*find_last(t_stack_node *stack);
long			ft_atol(const char *str);
int				is_sorted(t_stack_node *a);
int				stack_len(t_stack_node *a);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);

// Errors

int				error_synthax(char *str);
void			errors_free(t_stack_node **a);
void			free_stack(t_stack_node **stack);

// Inits and nodes

void			init_stack(t_stack_node **a, char **argv);
void			append_node(t_stack_node **stack, int n);

// Sort

void			sort_three(t_stack_node **a);

#endif