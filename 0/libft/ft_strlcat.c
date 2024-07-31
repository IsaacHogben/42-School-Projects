/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:05:33 by ihogben           #+#    #+#             */
/*   Updated: 2023/07/11 16:05:34 by ihogben          ###   ########.fr       */
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

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	start;

	i = 0;
	start = 0;
	while (dest[start] && start < size)
		start++;
	while (src[i] && (start + i + 1) < size)
	{
		dest[start + i] = src[i];
		i++;
	}
	if (start < size)
		dest[start + i] = '\0';
	return (start + ft_strlen(src));
}

// int	main()
// {
// 	char dest[30]; memset(dest, 0, 30);
// 	char * src = (char *)"AAAAAAAAA";
// 	dest[0] = 'B';

// 	memset(dest, 'B', 4);
// 	/* 3 */ printf("%zu", ft_strlcat(dest, src, 3));
// 			printf("\n%s", dest);
// }
