/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:35:04 by ihogben           #+#    #+#             */
/*   Updated: 2023/11/18 21:41:11 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
* @brief   Join Path and Command
*
* This function concatenates a path and a command with a '/' separator.
*
* @param   path        The path to be joined.
* @param   command     The command to be joined.
*
* @return  A dynamically allocated string representing 
*			the joined path and command.
*/
char	*join_path(char *path, char *command)
{
	char	*tmp;
	char	*ret;

	tmp = ft_strjoin(path, "/");
	ret = ft_strjoin(tmp, command);
	free(tmp);
	return (ret);
}

/*
* @brief   Validate and Retrieve Valid Command Path
*
* This function checks if a specified command is valid by checking the provided
* path and the paths in the shell program structure. If the command is found
* in any of the paths, the full path to the command is returned.
*
* @param   shell   Pointer to the shell program structure.
* @param   path    The path to be checked for the command.
*
* @return  If the command is found, the full path to the command.
*/
char	*command_valid(t_prog *shell, char *path)
{
	char	*tmp;
	int		i;

	if (!access(path, 0))
		return (path);
	i = 0;
	while (shell->paths[i])
	{
		tmp = join_path(shell->paths[i], path);
		if (access(tmp, F_OK) >= 0)
		{
			path = tmp;
			return (path);
		}
		free(tmp);
		i++;
	}
	return (NULL);
}

/*
* @brief   Execute Shell Command
*
* This function processes the shell command, validates its path, and
* executes the command using the execve system call. If the command is
* not valid or encounters an error, an appropriate error message is printed,
* and the shell exits with the specified exit status.
*
* @param   shell   Pointer to the shell program structure.
*/
void	out_process(t_prog *shell)
{
	char	*path;

	if (inbuilt_subprocess(shell))
		free_exit(shell, 0);
	free_array(shell->paths);
	path = find_env_var(shell, "PATH");
	shell->paths = ft_split(path, ':');
	free(path);
	free(shell->envp);
	convert_envp_to_array(shell);
	path = shell->commands[0];
	path = command_valid(shell, path);
	if (path)
	{
		execve(path, shell->commands, shell->envp);
	}
	perror("minishell: command not valid!");
	free_exit(shell, EXIT_FAILURE);
}
