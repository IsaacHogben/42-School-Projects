/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ints.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:25:25 by ihogben           #+#    #+#             */
/*   Updated: 2023/07/20 15:25:26 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_unsigned_nbr(unsigned int n)
{
	int	i;

	i = 0;
	if (n < 10)
		return (ft_putchar('0' + n));
	else
	{
		i += ft_put_unsigned_nbr(n / 10);
		i += ft_put_unsigned_nbr(n % 10);
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i = ft_putchar('-');
		i += ft_put_unsigned_nbr(-n);
	}
	else
		i = ft_put_unsigned_nbr(n);
	return (i);
}
