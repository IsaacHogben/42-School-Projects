/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:41:36 by ihogben           #+#    #+#             */
/*   Updated: 2023/07/13 12:41:41 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The calloc() function contiguously allocates enough space for count
//      objects that are size bytes of memory each and returns a pointer to the
//      allocated memory.  The allocated memory is filled with bytes of value
//      zero.

void	*ft_calloc(size_t count, size_t size)
{
	void	*point;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (count > 2147483647 || size > 2147483647 || count * size > 2147483647)
		return (NULL);
	point = malloc(count * size);
	if (point == NULL)
		return (NULL);
	ft_bzero(point, (count * size));
	return (point);
}
