/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 19:35:12 by jyap              #+#    #+#             */
/*   Updated: 2025/12/31 15:33:43 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	int				cost_a;
	int				cost_b;
	int				cheapest;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	int		size;
}	t_stack;

int		parse_args(int argc, char **argv, t_stack *a);
long	ft_atoi_safe(const char *str, int *error);
int		has_duplicates(t_stack *a);

t_node	*create_node(int value);
void	add_node_bottom(t_stack *stack, t_node *node);
void	free_stack(t_stack *stack);
int		is_sorted(t_stack *stack);

void	print_error(void);
int		is_number(char *str);

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

void	sort_two(t_stack *a);
void	sort_three(t_stack *a);
void	sort_five(t_stack *a, t_stack *b);

t_node	*find_min_node(t_stack *s);
t_node	*find_max_node(t_stack *s);
int		get_position(t_stack *s, t_node *target);

#endif