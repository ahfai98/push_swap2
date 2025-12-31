/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 19:35:38 by jyap              #+#    #+#             */
/*   Updated: 2025/12/31 15:20:16 by jyap             ###   ########.fr       */
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
	return (node);
}

void	add_node_bottom(t_stack *stack, t_node *node)
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

t_node	*find_min_node(t_stack *s)
{
	t_node	*min;
	t_node	*cur;

	if (!s || !s->head)
		return (NULL);
	min = s->head;
	cur = s->head->next;
	while (cur)
	{
		if (cur->value < min->value)
			min = cur;
		cur = cur->next;
	}
	return (min);
}

t_node	*find_max_node(t_stack *s)
{
	t_node	*max;
	t_node	*cur;

	if (!s || !s->head)
		return (NULL);
	max = s->head;
	cur = s->head->next;
	while (cur)
	{
		if (cur->value > max->value)
			max = cur;
		cur = cur->next;
	}
	return (max);
}
