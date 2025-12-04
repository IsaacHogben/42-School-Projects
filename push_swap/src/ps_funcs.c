/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_funcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:54:18 by ihogben           #+#    #+#             */
/*   Updated: 2023/09/05 15:54:20 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

int	ft_swap(t_stack	*toswap, int size)
{
	int	temp;

	if (toswap->top >= size - 1)
	{
		printf("stack too small\n");
		return (1);
	}
	temp = toswap->stack[toswap->top + 1];
	toswap->stack[toswap->top + 1] = toswap->stack[toswap->top + 2];
	toswap->stack[toswap->top + 2] = temp;
	return (0);
}

int	ft_push(t_stack *stack1, t_stack *stack2)
{
	if (stack2->stack[0] != 0)
	{
		ft_printf("Stack full?\n");
		return (1);
	}
	stack2->stack[stack2->top] = stack1->stack[stack1->top + 1];
	stack1->stack[stack1->top + 1] = 0;
	stack2->top--;
	stack1->top++;
	return (0);
}

int	ft_rotate(t_stack *torev, int size)
{
	int	temp;
	int	i;

	i = torev->top + 1;
	temp = torev->stack[i];
	while (i <= size)
	{
		torev->stack[i] = torev->stack[i + 1];
		i++;
	}
	torev->stack[size] = temp;
	return (0);
}

int	ft_reverse_rotate(t_stack *torev, int size)
{
	int	temp;

	temp = torev->stack[size];
	while (size > torev->top + 1)
	{
		torev->stack[size] = torev->stack[size - 1];
		size--;
	}
	torev->stack[size] = temp;
	return (0);
}
