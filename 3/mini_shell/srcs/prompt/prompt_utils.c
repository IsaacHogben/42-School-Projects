/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 21:46:49 by rmount            #+#    #+#             */
/*   Updated: 2023/12/03 19:35:35 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
- Called by build_prompt
- Applies the supplied colour to a string via string join
- Calls free_join to reapply default to the end of the string
*/
char	*prettify(char *str, char *colour)
{
	str = ft_strjoin(colour, str);
	str = free_join(str, ft_strdup(DEFAULT));
	return (str);
}

/*
- Called by prettify, build_prompt
- Joins 2 strings but frees the second string afterwards to avoid 
  memory leaks
*/
char	*free_join(char *s1, char *s2)
{
	char	*temp;

	temp = s1;
	s1 = ft_strjoin(temp, s2);
	free(temp);
	free(s2);
	return (s1);
}

/*
- Called by shell_loop
- Checks if the given string is blank
*/
bool	is_blank(char *str)
{
	int	i;

	if (!str)
		exit (0);
	i = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			return (false);
		i++;
	}
	return (true);
}
