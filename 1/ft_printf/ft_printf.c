/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:45:14 by ihogben           #+#    #+#             */
/*   Updated: 2023/07/20 12:45:16 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_do_print(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'u')
		return (ft_put_unsigned_nbr(va_arg(args, unsigned int)));
	if (c == 'x' || c == 'X')
		return (ft_printhex(va_arg(args, unsigned int), c));
	if (c == 'p')
		return (ft_putptr(va_arg(args, unsigned long long)));
	else if (c == '%')
		return (ft_putchar('%'));
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_do_print(str[i], args);
		}
		else
		{
			ft_putchar(str[i]);
			len++;
		}
		i++;
	}
	va_end (args);
	return (len);
}

// int	main()
// {
// 	printf("| %d : %d",
// 	ft_printf(" %p %p ", LONG_MIN, LONG_MAX),
// 	printf(" %p %p ", LONG_MIN, LONG_MAX)
// 	);
// }
