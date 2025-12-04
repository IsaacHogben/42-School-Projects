/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:22:37 by ihogben           #+#    #+#             */
/*   Updated: 2023/07/12 13:22:41 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h;
	size_t	n;

	h = 0;
	n = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[h] && h < len)
	{
		if (haystack[h] == needle[n])
		{
			while (haystack[h + n] == needle[n] && (n + h) < len)
			{
				if (!needle[n + 1])
					return ((char *)haystack + h);
				n++;
			}
			n = 0;
		}
		h++;
	}
	return (NULL);
}

// int	main()
// {
// 	char haystack[30] = "aaabcabcd";
// 	char needle[10] = "aabc";
// 	char * empty = (char*)"";
// 	/* 2 */ printf("%s : %s", ft_strnstr(haystack, needle, -1), haystack + 1);
// 	/* 10 */ printf("\n%s : %s", ft_strnstr(haystack, "abcd", 9), haystack + 5);
// }
