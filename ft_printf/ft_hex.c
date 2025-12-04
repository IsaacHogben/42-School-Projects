/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:23:10 by ihogben           #+#    #+#             */
/*   Updated: 2023/08/01 12:23:12 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned	long long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_puthex(unsigned long long n, const char format)
{
	if (n >= 16)
	{
		ft_puthex(n / 16, format);
		ft_puthex(n % 16, format);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + '0');
		else
		{
			if (format == 'x')
				ft_putchar(n - 10 + 'a');
			if (format == 'X')
				ft_putchar(n - 10 + 'A');
		}
	}
}

int	ft_printhex(unsigned long long h, const char format)
{
	if (h == 0)
		return (ft_putchar('0'));
	else
		ft_puthex(h, format);
	return (ft_hex_len(h));
}

int	ft_putptr(unsigned long long p)
{
	int	len;

	len = ft_putstr("0x");
	len += ft_printhex(p, 'x');
	return (len);
}
