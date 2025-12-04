/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:46:23 by rmount            #+#    #+#             */
/*   Updated: 2023/12/03 19:18:36 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
- Called by the main function
- Takes in the shell and the envp from main
- Adds all of envp to the environment variables, then also overwrites the shell 
  and pwd env vars with the relevant ones for our shell.
*/
void	init_env_list(t_prog *shell, char **envp)
{
	char	buffer[1024];

	if (!envp)
		return ;
	while (*envp)
	{
		add_env_var_full(shell, *envp);
		envp++;
	}
	add_env_var(shell, "SHELL=", "minishell");
	shell->paths = ft_split(getenv("PATH"), ':');
	add_env_var(shell, "PWD=", getcwd(buffer, sizeof(buffer)));
}
