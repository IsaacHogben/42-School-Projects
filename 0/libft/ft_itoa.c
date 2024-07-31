/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:15:16 by ihogben           #+#    #+#             */
/*   Updated: 2023/07/16 15:15:20 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates (with malloc(3)) and returns a string
// representing the integer received as an argument.
// Negative numbers must be handled.

static unsigned int	ft_getlen(int long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len += 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

long int	ft_abv(long int nbr)
{
	if (nbr < 0)
		return (-nbr);
	else
		return (nbr);
}

char	*ft_itoa(int n)
{
	int		len;
	int		sign;
	char	*str;

	sign = 1;
	if (n < 0)
		sign = -1;
	len = ft_getlen(n);
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (0);
	str[len] = '\0';
	len--;
	while (len >= 0)
	{
		str[len] = '0' + ft_abv(n % 10);
		n = ft_abv(n / 10);
		len--;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}
// int main()
// {
// 	printf("%s", ft_itoa(-2147483648));
// 	//printf("\n:%s", ft_itoa(123456));
// }
