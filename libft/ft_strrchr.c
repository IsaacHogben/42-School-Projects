/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:42:49 by ihogben           #+#    #+#             */
/*   Updated: 2023/07/12 11:42:51 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int chr)
{
	unsigned char	i;
	int				c;

	i = chr;
	c = ft_strlen(s);
	if (!ft_isascii(i))
		return ((char *)s);
	if (i == '\0')
		return ((char *)s + c);
	while (c >= 0)
	{
		if (s[c] == i)
			return ((char *)s + c);
		c--;
	}
	return (NULL);
}
