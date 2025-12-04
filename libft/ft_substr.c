/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:41:19 by ihogben           #+#    #+#             */
/*   Updated: 2023/07/13 13:41:20 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates (with malloc(3)) and returns a substring
// from the string ’s’.
// The substring begins at index ’start’ and is of
// maximum size ’len’.

//limit len to size of s to reduce memory waste.

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	int		size;

	if (start > 2147483647 || len > 2147483647)
		len = 0;
	size = len;
	if (len > ft_strlen(s))
		size = ft_strlen(s);
	i = 0;
	substr = (char *)malloc(sizeof(char) * (size + 1));
	if (substr == NULL || s == NULL)
		return (NULL);
	while (i < len && s[start + i] && start < ft_strlen(s))
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
