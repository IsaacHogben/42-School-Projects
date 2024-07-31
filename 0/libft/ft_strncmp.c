/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:00:11 by ihogben           #+#    #+#             */
/*   Updated: 2023/07/12 12:00:12 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// DESCRIPTION
//      The strcmp() and strncmp() functions lexicographically compare the null-
//      terminated strings s1 and s2.

//      The strncmp() function compares not more than n characters.  Because
//      strncmp() is designed for comparing strings rather than binary data,
//      characters that appear after a `\0' character are not compared.

// RETURN VALUES
//      The strcmp() and strncmp() functions return an integer greater than,
//      equal to, or less than 0, according as the string s1 is greater than,
//      equal to, or less than the string s2.  The comparison is done using
//      unsigned characters, so that `\200' is greater than `\0'.

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] == s1[i] && i < n)
		++i;
	if (i == n)
		return (0);
	return (*(unsigned char *)&s1[i] - *(unsigned char *)&s2[i]);
}
