/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:00:00 by ihogben           #+#    #+#             */
/*   Updated: 2023/11/24 15:42:40 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * @brief	Updates the PWD and OLDPWD environment variables on directory change.
 * @param	path: The path that will be changed to
*/
void	update_pwd(t_prog *shell, char *path)
{
	char	*old_pwd;
	char	*new_pwd;
	char	*var;
	char	buffer[1024];

	chdir(path);
	var = find_env_var(shell, "PWD");
	old_pwd = ft_strjoin("OLDPWD=", var);
	add_env_var_full(shell, old_pwd);
	free(var);
	free(old_pwd);
	new_pwd = ft_strjoin("PWD=", getcwd(buffer, sizeof(buffer)));
	add_env_var_full(shell, new_pwd);
	free(new_pwd);
	build_prompt(shell);
}

bool	root_directory(t_prog *shell)
{
	update_pwd(shell, "/");
	return (true);
}

/*
 * @brief	Takes the location of the current working directory and appends the
 * input path to it.
 * @param	target_dir: the directory we want to go to
 * @returns	path: full path of desired directory
*/
char	*relative_path(char *target_dir)
{
	char	*path;
	char	*tmp;
	char	buffer[1024];

	path = ft_strjoin(getcwd(buffer, sizeof(buffer)), "/");
	tmp = path;
	path = ft_strjoin(path, target_dir);
	free(tmp);
	return (path);
}

/*
 * @brief	Checks the user input path to see if it has no arguments, an agrument
 * for an adjacent directory, or an absolute path. It then checks if that
 * directory is valid or if the user can access it before attempting to redirect.
 * 
 * @returns	true: boolean to indicate this is a built-in function
 * ! Needs to check whether what is entered is a directory
*/
bool	change_directory(t_prog *shell)
{
	char	*path;
	char	*target_dir;

	target_dir = shell->user_inputs[1];
	if (!target_dir)
		return (root_directory(shell));
	else if (target_dir[0] == '/')
		path = ft_strdup(target_dir);
	else
		path = relative_path(target_dir);
	if (access(path, F_OK) < 0)
	{
		perror("cd: path not found\n");
		g_exit_status = 1;
	}
	else
		update_pwd(shell, path);
	free(path);
	return (true);
}
