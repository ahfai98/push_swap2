/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 19:35:38 by jyap              #+#    #+#             */
/*   Updated: 2025/12/30 20:07:38 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->cost_a = 0;
	node->cost_b = 0;
	node->cheapest = 0;
	node->next = NULL;
	node->above_median = 0;
	return (node);
}

void	add_note_bottom(t_stack *stack, t_node *node)
{
	t_node	*tmp;

	if (!stack->head)
		stack->head = node;
	else
	{
		tmp = stack->head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
	stack->size++;
}

void	free_stack(t_stack *stack)
{
	t_node	*tmp;

	while (stack->head)
	{
		tmp = stack->head;
		stack->head = stack->head->next;
		free(tmp);
	}
	stack->size = 0;
}

int	is_sorted(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->head;
	while (tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
