/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:15:20 by ihogben           #+#    #+#             */
/*   Updated: 2023/07/11 15:15:24 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// DESCRIPTION
//      The strlcpy() and strlcat() functions copy and concatenate strings with
//      the same input parameters and output result as snprintf(3).  They are
//      designed to be safer, more consistent, and less error prone replacements
//      for the easily misused functions strncpy(3) and strncat(3).

//      strlcpy() and strlcat() take the full size of the destination buffer and
//      guarantee NUL-termination if there is room.  Note that room for the NUL
//      should be included in dstsize.

//      strlcpy() copies up to dstsize - 1 characters from the string src to
//      dst, NUL-terminating the result if dstsize is not 0.

// RETURN VALUES

//      The strlcpy() and strlcat() functions return the total
//      length of the string they tried to create.  For strlcpy() that means the
//      length of src.  For strlcat() that means the initial length of dst plus
//      the length of src.

//      If the return value is >= dstsize, the output string has been truncated.
//      It is the caller's responsibility to handle this.

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (i < size - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if (i < size)
		dest[i] = '\0';
	while (src[i])
		i++;
	return (i);
}
