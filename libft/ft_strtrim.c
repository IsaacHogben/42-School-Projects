/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:02:45 by ihogben           #+#    #+#             */
/*   Updated: 2023/07/13 15:02:47 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates (with malloc(3)) and returns a copy of
// ’s1’ with the characters specified in ’set’ removed
// from the beginning and the end of the string.

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*strtrim;
	size_t	i;

	i = 0;
	start = 0;
	end = ft_strlen(s1);
	if (*s1 == '\0')
		return (ft_calloc(1, 1));
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (s1[end - 1] && ft_strchr(set, s1[end - 1]) && end > start && end > 0)
		end--;
	strtrim = malloc(sizeof(char) * (end - start + 1));
	if (strtrim == NULL)
		return (NULL);
	ft_strlcpy(strtrim, &s1[start], end - start + 1);
	return (strtrim);
}

// int	main()
// {
// 	printf("%s\n", ft_strtrim("   xxx   xxx", " x"));
// }