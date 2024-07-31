/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 10:17:33 by rmount            #+#    #+#             */
/*   Updated: 2023/12/03 18:57:59 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief   Remove Environment Variable
 *
 * This function removes an environment variable with the specified key from the
 * shell's environment variables list. It iterates through the linked list,
 * finds the variable, adjusts the list pointers, and frees the memory associated
 * with the removed variable.
 *
 * @param   shell   Pointer to the shell program structure.
 * @param   str     The key of the environment variable to be removed.
 */
void	remove_env(t_prog *shell, char *str)
{
	t_list	*lst;
	t_list	*prev;
	t_env	*current;

	lst = shell->env_vars;
	prev = NULL;
	current = lst->content;
	while (lst)
	{
		if (!ft_strcmp(str, current->key))
		{
			if (prev)
				prev->next = lst->next;
			else
				shell->env_vars = shell->env_vars->next;
			free_env(&lst);
			free(lst);
			return ;
		}
		prev = lst;
		lst = lst->next;
		if (lst)
			current = lst->content;
	}
}

/*
- Called by add_env_var_full
- Takes an env var and the string to replace it with
- Assigns the env_var's attributes to the appropriate pieces of str
- Assigns the new content to the existing env var
*/
void	edit_env_var(t_list **env_var_list, char *str, int i)
{
	t_env	*env_var;
	t_list	*current;

	current = *env_var_list;
	env_var = malloc(sizeof(*env_var) * (sizeof(char *) * 3));
	env_var->env_var = ft_strdup(str);
	env_var->key = ft_substr(str, 0, i);
	env_var->value = ft_substr(str, i + 1, ft_strlen(&str[i]));
	current->content = env_var;
}

/*
- Called by add_env_var
- Takes in the shell struct and the full env var as a string
- Sets the temp env_var_list to the shell's current env_vars
- Iterates through str until reaching '='
- If new_env_var has a key and the key matches the current 
  existing env var key and there's no value after the '=',
  we free the existing env var and edit it to have the str
  instead.
- If the new_env_var's key does not exist, we make a new env var node,
  call edit_env_var to overwrite the content of the new node with str,
  then add the new node to the back of the env_var_list
*/
void	add_env_var_full(t_prog *shell, char *str)
{
	t_env	*new_env_var;
	t_list	*env_var_list;
	int		i;

	i = 0;
	env_var_list = shell->env_vars;
	while (str[i] && str[i] != '=')
		i++;
	while (env_var_list)
	{
		new_env_var = env_var_list->content;
		if (new_env_var->key && !ft_strncmp(new_env_var->key, str, i)
			&& !new_env_var->key[i])
		{
			free_env_var(&env_var_list);
			edit_env_var(&env_var_list, str, i);
			return ;
		}
		env_var_list = env_var_list->next;
	}
	env_var_list = ft_lstnew(NULL);
	edit_env_var(&env_var_list, str, i);
	ft_lstadd_back(&shell->env_vars, env_var_list);
}

/*
- Called by init_env_list
- Takes in the shell struct, the key (name of the env var) and value (content)
  of the env var)
- Joins the key and value together and passes it to add_env_var_full function
  then frees the temp_env_var
*/
void	add_env_var(t_prog *shell, char *key, char *value)
{
	char	*temp_env_var;

	temp_env_var = ft_strjoin(key, value);
	add_env_var_full(shell, temp_env_var);
	free(temp_env_var);
}
