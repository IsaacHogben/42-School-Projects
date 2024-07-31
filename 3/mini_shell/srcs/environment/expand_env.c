/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 21:20:33 by rmount            #+#    #+#             */
/*   Updated: 2023/12/03 21:09:37 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief   Find Environment Variable Value
 *
 * This function searches for the value of a specified environment variable
 * in the shell's environment variables list. It iterates through the linked
 * list of environment variables and returns the value of the variable if found.
 * If the variable is not found, an empty string is returned.
 *
 * @param   shell   Pointer to the shell program structure.
 * @param   var     The name of the environment variable to find.
 *
 * @return  A newly allocated string containing the value of the specified
 *          environment variable. If the variable is not found, an empty string
 *          is returned.
 */
/*
- Called by build_prompt
- Takes the shell and a string of the var being searched for.
- Compares the supplied var to the keys in the linked list, if
  a match is found, we return the value associated with the key.
  If no match is found we return empty space.
*/
char	*find_env_var(t_prog *shell, char *var)
{
	t_env	*env_var;
	t_list	*env_var_list;

	env_var_list = shell->env_vars;
	while (env_var_list)
	{
		env_var = env_var_list->content;
		if (!ft_strcmp(env_var->key, var))
			return (ft_strdup(env_var->value));
		env_var_list = env_var_list->next;
	}
	return (ft_strdup(""));
}
