/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:54:55 by ihogben           #+#    #+#             */
/*   Updated: 2023/11/12 15:54:56 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief	Adds a variable that is not a part of the environment variables.
 * 
 * When printing the environment variable list, this will not be included, but
 * it can still be called on in the shell
 * 
 * @param	var: the variable to be added
 * 
 * @returns	boolean true
**/

bool	add_var(t_prog *shell, char *var)
{
	add_env_var_full(shell, var);
	return (true);
}

/**
 * @brief	Checks to see if the command entered by the user is one of the
 * recreated inbuilt functions. 
 * 
 * These functions are executed in the main
 * process to ensure that they are handled in the same way that the real
 * shell handles them.
 * 
 * @returns	boolean true if the command was found, false if not.
**/

bool	inbuilt_check(t_prog *shell)
{
	if (!*shell->user_inputs)
		return (false);
	if (!ft_strcmp("cd", shell->user_inputs[0]))
		return (change_directory(shell));
	if (!ft_strcmp("export", shell->user_inputs[0]))
		return (builtin_export(shell));
	if (!ft_strcmp("unset", shell->user_inputs[0]))
		return (builtin_unset(shell));
	if (!ft_strcmp("exit", shell->user_inputs[0]))
	{
		if (shell->user_inputs[1])
			free_exit(shell, ft_atoi(shell->user_inputs[1]));
		free_exit(shell, 0);
	}
	if (ft_strchr(shell->user_inputs[0], '='))
		return (add_var(shell, shell->user_inputs[0]));
	return (false);
}

/**
 * @brief	Checks to see if the command entered by the user is one of the
 * recreated inbuilt functions. These functions are executed in a sub-process
 * to ensure that they are handled in the same way that the real shell handles
 * them.
 * 
 * @returns	boolean true if the command was found, false if not.
**/

bool	inbuilt_subprocess(t_prog *shell)
{
	if (!ft_strcmp("echo", shell->commands[0]))
		return (builtin_echo(shell));
	if (!ft_strcmp("pwd", shell->commands[0]))
		return (builtin_pwd(shell));
	if (!ft_strcmp("env", shell->commands[0]))
		return (builtin_env(shell));
	return (false);
}
