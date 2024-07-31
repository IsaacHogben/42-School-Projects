/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:58:39 by ihogben           #+#    #+#             */
/*   Updated: 2023/12/03 12:11:02 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
* @brief   Process the Next Shell Command
*
* This function updates and reallocates the user inputs array, splits the
* arguments, and executes the next command in the shell program. It calls
* the 'command' function to perform the necessary operations for command
* execution.
*
* @param   shell   Pointer to the shell program structure.
*/
void	next_command(t_prog *shell)
{
	shell->user_inputs = update_array(shell->user_inputs);
	if (!shell->user_inputs)
		return ;
	shell->user_inputs = realloc_back(shell->user_inputs,
			shell->user_inputs[1]);
	split_args(shell, *shell->user_inputs);
	command(shell);
}

/**
 * @brief   Execute a command in a subprocess.
 *
 * This function checks if user inputs are available and if the command is not
 * a built-in command. If conditions are met, it forks a new process, with the
 * child process executing the command using check_pipes(). The parent process
 * sets up signal handlers for SIGINT and SIGQUIT, waits for the child process
 * to finish, and then enters a loop to process the next command.
 *
 * @param   shell   Pointer to the shell program structure (t_prog).
 */
void	command(t_prog *shell)
{
	if (shell->user_inputs && !inbuilt_check(shell))
	{
		shell->pid = fork();
		if (!shell->pid)
		{
			check_pipes(shell);
		}
		signal(SIGINT, ctrl_handler_subprocess);
		signal(SIGQUIT, backslash_handler);
		waitpid(shell->pid, &g_exit_status, 0);
	}
	while (shell->user_inputs)
		next_command(shell);
}
