/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 19:35:12 by jyap              #+#    #+#             */
/*   Updated: 2025/12/30 19:35:13 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	int				index;
	int				cost_a;
	int				cost_b;
	int				cheapest;
	struct s_node	*next;
	int				above_median;
}	t_node;

typedef struct s_stack
{
	t_node *head;
	int size;
} t_stack;

int     parse_args(int argc, char **argv, t_stack *a);
long    ft_atoi_safe(const char *str, int *error);
int     has_duplicates(t_stack *a);

t_node  *create_node(int value);
void    add_node_bottom(t_stack *stack, t_node *node);
void    free_stack(t_stack *stack);
int     is_sorted(t_stack *stack);

void    print_error(void);
int		is_number(char *str);

#endif