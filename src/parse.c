/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 18:57:55 by jyap              #+#    #+#             */
/*   Updated: 2025/12/30 19:35:29 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	set_error(int *error)
{
	*error = 1;
	return (0);
}

long	ft_atoi_safe(const char *str, int *error)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	if (!str)
		return (set_error(error));
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
		if (str[i - 1] == '-')
			sign = -1;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (set_error(error));
		res = res * 10 + str[i] - '0';
		if (res * sign > INT_MAX || res * sign < INT_MIN)
			return (set_error(error));
		i++;
	}
	return (res * sign);
}

static int	add_to_stack(t_stack *a, int value)
{
	t_node	*node;

	node = create_node(value);
	if (!node)
		return (0);
	add_node_bottom(a, node);
	return (1);
}

int	has_duplicates(t_stack *a)
{
	t_node	*tmp;
	t_node	*tmp2;

	if (!a)
		return (0);
	tmp = a->head;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->value == tmp2->value)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

int	parse_args(int ac, char **av, t_stack *a)
{
	int		i;
	int		error;
	long	val;
	char	*arg;

	i = 1;
	error = 0;
	val = 0;
	while (i < ac)
	{
		error = 0;
		arg = av[i];
		if (!is_number(arg))
			return (0);
		val = ft_atoi_safe(arg, &error);
		if (error || !add_to_stack(a, (int)val))
			return (0);
		i++;
	}
	if (has_duplicates(a))
		return (0);
	return (1);
}
