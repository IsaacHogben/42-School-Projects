/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:45:19 by rmount            #+#    #+#             */
/*   Updated: 2023/12/03 18:48:26 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Iterates through full env var list, freeing each
// by calling free_env_var
void	free_env_var_list(t_prog *shell)
{
	t_list	*env_var_list;

	env_var_list = shell->env_vars;
	while (env_var_list)
	{
		free_env_var(&env_var_list);
		env_var_list = env_var_list->next;
	}
}

// Frees one env var from the env_var_list
void	free_env_var(t_list **env_var_list)
{
	t_env	*env;
	t_list	*current;

	current = *env_var_list;
	env = current->content;
	free(env->env_var);
	free(env->key);
	free(env->value);
	free(env);
}
