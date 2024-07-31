/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:07:13 by ihogben           #+#    #+#             */
/*   Updated: 2023/11/13 16:07:18 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* @brief   Reallocate Array Truncated from a Specific Delimiter
*
* This function reallocates a string array (arr) by truncating it from a
* specified delimiter (delim). It creates a new array that starts from the
* position after the delimiter and continues until the end of the original array.
* The original array is then freed.
*
* @param   arr     The original string array to be reallocated.
* @param   delim   The delimiter specifying the truncation point.
*
* @return  A newly allocated string array truncated from the specified delimiter.
*          If the delimiter is not found or is the first element of the array,
*          the original array is returned without reallocation.
*          If the resulting array has only one element and it is equal to ")",
*          the function returns NULL, indicating a special case.
*/
char	**realloc_back(char **arr, char *delim)
{
	char	**ret;
	int		i;
	int		len;

	if (!delim || !ft_strcmp(arr[0], delim))
		return (arr);
	i = 0;
	while (arr[i] && ft_strcmp(arr[i], delim))
		i++;
	len = i;
	while (arr[len] && ft_strcmp(arr[len], ""))
		len++;
	ret = malloc(sizeof(*ret) * (len - i + 1));
	len = 0;
	while (arr[i] && ft_strcmp(arr[i], ""))
		ret[len++] = ft_strdup(arr[i++]);
	ret[len] = NULL;
	free_array(arr);
	if (!ret[1] && !ft_strcmp(ret[0], ")"))
	{
		free_array(ret);
		return (NULL);
	}
	return (ret);
}
