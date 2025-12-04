/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:45:39 by ihogben           #+#    #+#             */
/*   Updated: 2023/09/05 12:45:42 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

t_stackab	initialize(int argc, char **argv)
{
	t_stackab	stacks;
	int			size;

	stacks.a.stack = format_list(&stacks, argc, argv);
	stacks.a.top = -1;
	size = stacks.size;
	stacks.b.stack = malloc(sizeof(int) * size);
	stacks.b.top = size;
	while (size >= 0)
	{
		stacks.b.stack[size] = 0;
		size--;
	}
	return (stacks);
}

void	view_stack(t_stackab stack)
{
	int	i;

	i = 0;
	ft_printf("%d_%d\n", stack.a.top, stack.b.top);
	while (i <= stack.size)
	{
		ft_printf("%d-%d\n", stack.a.stack[i], stack.b.stack[i]);
		i++;
	}
}

int	is_sorted(t_stackab *s)
{
	int	i;

	i = 0;
	while (i < s->size)
	{
		if (s->a.stack[i] != s->a.stack[i + 1] - 1)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stackab	stackab;

	if (argc < 2)
		return (1);
	stackab = initialize(argc, argv);
	argc = stackab.size + 1;
	if (is_sorted(&stackab))
	{
		free(stackab.a.stack);
		free(stackab.b.stack);
		return (0);
	}
	if (argc == 2)
		two_sort(&stackab);
	else if (argc == 3)
		three_sort(&stackab);
	else if (argc <= 5)
		small_sort(&stackab);
	else if (argc > 5)
		big_sort(&stackab);
	free(stackab.a.stack);
	free(stackab.b.stack);
	return (0);
}
