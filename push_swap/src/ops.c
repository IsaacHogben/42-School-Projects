/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:10:45 by ihogben           #+#    #+#             */
/*   Updated: 2023/09/05 15:10:47 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

void	swap(t_stackab *stackab, char *c)
{
	if (c[1] == 'a')
		ft_swap(&stackab->a, stackab->size);
	else if (c[1] == 'b')
		ft_swap(&stackab->b, stackab->size);
	else if (c[1] == 's')
	{
		ft_swap(&stackab->a, stackab->size);
		ft_swap(&stackab->b, stackab->size);
	}
}

void	push(t_stackab *stackab, char *c)
{
	if (c[1] == 'a')
		ft_push(&stackab->b, &stackab->a);
	else if (c[1] == 'b')
		ft_push(&stackab->a, &stackab->b);
}

void	rotate(t_stackab *stackab, char *c)
{
	if (c[1] == 'a')
		ft_rotate(&stackab->a, stackab->size);
	else if (c[1] == 'b')
		ft_rotate(&stackab->b, stackab->size);
	else if (c[1] == 'r')
	{
		ft_rotate(&stackab->a, stackab->size);
		ft_rotate(&stackab->b, stackab->size);
	}
}

void	reverse_rotate(t_stackab *stackab, char *c)
{
	if (c[2] == 'a')
		ft_reverse_rotate(&stackab->a, stackab->size);
	else if (c[2] == 'b')
		ft_reverse_rotate(&stackab->b, stackab->size);
	else if (c[2] == 'r')
	{
		ft_reverse_rotate(&stackab->a, stackab->size);
		ft_reverse_rotate(&stackab->b, stackab->size);
	}
}

int	do_op(t_stackab *stackab, char *c)
{
	ft_printf("%s\n", c);
	if (c[0] == 's')
		swap(stackab, c);
	else if (c[0] == 'p')
		push(stackab, c);
	else if (c[0] == 'r')
	{
		if (c[2] != '\0')
			reverse_rotate(stackab, c);
		else
			rotate(stackab, c);
	}
	else
		return (1);
	return (0);
}
