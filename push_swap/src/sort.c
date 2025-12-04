/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 13:21:38 by ihogben           #+#    #+#             */
/*   Updated: 2023/09/10 13:22:41 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

void	big_sort(t_stackab *stackab)
{
	int	max_bits;
	int	i;
	int	j;

	i = 0;
	j = 0;
	max_bits = 0;
	while (((stackab->size + 1) >> max_bits) != 0)
		max_bits++;
	while (i < max_bits)
	{
		while (j <= stackab->size)
		{
			if (((stackab->a.stack[stackab->a.top + 1] >> i) & 1) == 1)
				do_op(stackab, "ra");
			else
				do_op(stackab, "pb");
			j++;
		}
		j = 0;
		i++;
		while (stackab->b.top < stackab->size)
			do_op(stackab, "pa");
	}
}

void	two_sort(t_stackab *stackab)
{
	if (stackab->a.stack[stackab->a.top + 1]
		> stackab->a.stack[stackab->a.top + 2])
		do_op(stackab, "sa");
}

void	three_sort(t_stackab *s)
{
	if ((s->a.stack[s->a.top + 1] > s->a.stack[s->a.top + 2])
		&& (s->a.stack[s->a.top + 1] > s->a.stack[s->a.top + 3]))
		do_op(s, "ra");
	if ((s->a.stack[s->a.top + 1] > s->a.stack[s->a.top + 2])
		|| (s->a.stack[s->a.top + 1] > s->a.stack[s->a.top + 3]))
		do_op(s, "sa");
	if ((s->a.stack[s->a.top + 1] > s->a.stack[s->a.top + 2])
		&& (s->a.stack[s->a.top + 1] > s->a.stack[s->a.top + 3]))
	{
		do_op(s, "sa");
		do_op(s, "rra");
	}
	if ((s->a.stack[s->a.top + 1] < s->a.stack[s->a.top + 2])
		&& (s->a.stack[s->a.top + 1] < s->a.stack[s->a.top + 3]))
	{
		if ((s->a.stack[s->a.top + 2] > s->a.stack[s->a.top + 1])
			&& (s->a.stack[s->a.top + 2] > s->a.stack[s->a.top + 3]))
		{
			do_op(s, "ra");
			do_op(s, "sa");
			do_op(s, "rra");
		}
	}
}

void	small_sort(t_stackab *s)
{
	while (s->b.top >= 3)
		do_op(s, "pb");
	three_sort(s);
	if (((s->b.stack[s->b.top + 1] < s->b.stack[s->b.top + 2])
			&& ((s->b.stack[s->b.top + 1] != 1)
				&& (s->b.stack[s->b.top + 2] != 5)))
		|| ((s->b.stack[s->b.top + 1] == 5) && (s->b.stack[s->b.top + 2] == 1))
		|| ((s->b.stack[s->b.top + 1] == 1) && (s->b.stack[s->b.top + 2] == 2))
		|| ((s->b.stack[s->b.top + 1] == 4) && (s->b.stack[s->b.top + 2] == 5)))
		do_op(s, "sb");
	while (s->a.top != -1)
		if ((s->a.stack[s->a.top + 1] - 1 == s->b.stack[s->b.top + 1])
			|| (s->a.stack[s->a.top + 1] + (s->size)
				== s->b.stack[s->b.top + 1]))
			do_op(s, "pa");
	else
		do_op(s, "rra");
	while (s->a.stack[s->a.top + 1] != 1)
		if (s->a.stack[s->a.top + 1] > 3)
			do_op(s, "ra");
	else
		do_op(s, "rra");
}
