/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_envp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:40:01 by rmount            #+#    #+#             */
/*   Updated: 2023/12/03 19:13:56 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
- Called by the main function
As the enviroment variables are kept as a linked list, we need to convert the 
env vars to an array of strings to make it easier to find and alter particular
env vars. 
- Iterates through the shell's env_vars, adding the full env var text for each
  to the array (envp), then assigns the array to shell's envp attribute.
*/
void	convert_envp_to_array(t_prog *shell)
{
	int		size;
	int		i;
	char	**envp;
	t_list	*env_var_list;
	t_env	*env_var;

	i = 0;
	size = ft_lstsize(shell->env_vars);
	envp = malloc(sizeof(*envp) * (size + 1));
	env_var_list = shell->env_vars;
	while (env_var_list)
	{
		env_var = env_var_list->content;
		envp[i] = env_var->env_var;
		i++;
		env_var_list = env_var_list->next;
	}
	envp[i] = NULL;
	shell->envp = envp;
}
