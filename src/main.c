/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 19:35:07 by jyap              #+#    #+#             */
/*   Updated: 2025/12/31 15:29:43 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_cases(t_stack *a, t_stack *b)
{
	if (a->size == 1)
		return ;
	if (a->size == 2)
		sort_two(a);
	else if (a->size <= 3)
		sort_three(a);
	else if (a->size <= 5)
		sort_five(a, b);
	//else
	//	sort_big(a, b);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac < 2)
		return (0);
	a.head = NULL;
	a.size = 0;
	b.head = NULL;
	b.size = 0;
	if (!parse_args(ac, av, &a))
	{
		print_error();
		return (1);
	}
	if (is_sorted(&a))
	{
		free_stack(&a);
		return (0);
	}
	sort_cases(&a, &b);
	if (is_sorted(&a) && b.size == 0)
		write(1, "Sorted\n", 7);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
