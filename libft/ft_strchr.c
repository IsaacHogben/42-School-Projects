/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:09:46 by ihogben           #+#    #+#             */
/*   Updated: 2023/07/12 11:09:48 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The strchr() function locates the first occurrence of i (converted to a
//      char) in the string pointed to by s.  The terminating null character is
//      considered to be part of the string; therefore if i is `\0', the func-
//      tions locate the terminating `\0'

char	*ft_strchr(const char *s, int c)
{
	unsigned char	i;

	i = c;
	if (!ft_isascii(i))
		return ((char *)s);
	while (*s)
	{
		if (*s == i)
			return ((char *)s);
		s++;
	}
	if (i == '\0')
		return ((char *)s);
	return (NULL);
}
