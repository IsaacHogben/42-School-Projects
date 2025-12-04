/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:50:30 by ihogben           #+#    #+#             */
/*   Updated: 2023/07/11 14:50:35 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	size_t	size;
	char	*d;
	char	*s;

	size = n;
	d = (char *)str1;
	s = (char *)str2;
	if (d == s)
		return (d);
	if (s < d)
	{
		while (size--)
			d[size] = s[size];
		return (str1);
	}
	while (size--)
		*d++ = *s++;
	return (str1);
}
