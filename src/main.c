/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 19:35:07 by jyap              #+#    #+#             */
/*   Updated: 2025/12/30 19:36:07 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	/*
	if (a.size <= 3)
		sort_three(&a);
	else if (a.size <= 5)
		sort_five(&a, &b);
	else
		sort_big(&a, &b);
	*/
	free_stack(&a);
	free_stack(&b);
	return (0);
}
