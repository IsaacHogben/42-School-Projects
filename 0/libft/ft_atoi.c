/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:56:03 by ihogben           #+#    #+#             */
/*   Updated: 2023/07/13 11:56:05 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(char c)
{
	if (c == 32 || c == '\n' || c == '\t')
		return (1);
	else if (c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	norp;
	int	r;

	i = 0;
	norp = 0;
	r = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || (str[i] == '+'))
	{
		if (str[i++] == '-')
			norp--;
		else
			norp++;
	}
	while (str[i] >= '0' && (str[i] <= '9'))
	{
		if (norp == -1)
			r = (r * 10) - (str[i++] - 48);
		else
			r = (r * 10) + (str[i++] - 48);
	}
	return (r);
}
