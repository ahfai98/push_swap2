/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 19:35:35 by jyap              #+#    #+#             */
/*   Updated: 2025/12/31 15:00:33 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//move largest to the bottom first, then swap first two if needed
void	sort_three(t_stack *a)
{
	t_node	*n1;
	t_node	*n2;
	t_node	*n3;
	t_node	*max;

	if (!a || a->size != 3)
		return ;
	n1 = a->head;
	n2 = n1->next;
	max = find_max_node(a);
	if (n1 == max)
		ra(a);
	else if (n2 == max)
		rra(a);
	if (find_min_node(a) != a->head)
		sa(a);
}

//push two smallest number to b, then push them back after sorting 3
void	sort_five(t_stack *a, t_stack *b)
{
	int		count;
	t_node	*min;
	int		pos;

	if (!a || a->size < 4 || a->size > 5)
		return ;
	count = a->size - 3;
	while (count--)
	{
		min = find_min_node(a);
		while (a->head != min)
		{
			pos = get_position(a, min);
			if (pos <= a->size / 2)
				ra(a);
			else
				rra(a);
		}
		pb(a, b);
	}
	sort_three(a);
	while (b->size)
		pa(a, b);
}
