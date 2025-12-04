/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:24:39 by ihogben           #+#    #+#             */
/*   Updated: 2023/12/03 12:11:02 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief   Split Commands with Pipe
 *
 * This function sets up a pipe, forks a child process, and redirects the
 * standard input/output based on the pipe. The parent and child processes
 * then execute different parts of the shell command based on the presence
 * of a pipe ('|') in the user inputs.
 *
 * @param   shell   Pointer to the shell program structure.
 */
void	pipe_split(t_prog *shell)
{
	int	pid;
	int	pipefd[2];

	pipe(pipefd);
	pid = fork();
	if (pid)
	{
		if (!shell->pid)
			shell->pid = pid;
		close(pipefd[1]);
		dup2(pipefd[0], 0);
		close(pipefd[0]);
		signal(SIGINT, ctrl_handler_subprocess);
	}
	else
	{
		close(pipefd[0]);
		dup2(pipefd[1], 1);
		close(pipefd[1]);
		out_process(shell);
	}
}

/**
 * @brief   Execute the Last Shell Command
 *
 * This function executes the last shell command in the user inputs.
 * It handles forking a child process, executing the command, waiting for
 * both the child and parent processes, and then normalizing the exit status.
 *
 * @param   shell   Pointer to the shell program structure.
 */
void	last_command(t_prog *shell)
{
	int	pid;

	if (!shell->pid)
		out_process(shell);
	pid = fork();
	if (!pid)
		out_process(shell);
	waitpid(shell->pid, &g_exit_status, 0);
	waitpid(pid, &g_exit_status, 0);
	normalise_exit();
	free_exit(shell, g_exit_status);
}

/**
 * @brief   Set Commands for Execution
 *
 * This function sets up the commands array in the shell program structure
 * based on the user inputs. If there is no pipe ('|') in the user inputs,
 * the commands array is set directly; otherwise, it extracts the commands
 * before the pipe for execution.
 *
 * @param   shell   Pointer to the shell program structure.
 */
void	set_commands(t_prog *shell)
{
	int		i;
	int		j;
	char	**current;

	current = shell->user_inputs;
	i = 0;
	while (current[i] && strcmp("|", current[i]))
		i++;
	if (!current[i])
	{
		shell->commands = current;
	}
	else
	{
		shell->commands = malloc(sizeof(*shell->commands) * (i + 1));
		j = 0;
		while (j < i)
		{
			shell->commands[j] = current[j];
			j++;
		}
		shell->commands[i] = NULL;
	}
}

/**
 * @brief   Execute Shell Commands
 *
 * This function orchestrates the execution of shell commands. It sets up the
 * commands array in the shell program structure, handles the splitting of
 * commands with a pipe, and frees resources related to command execution.
 *
 * @param   shell   Pointer to the shell program structure.
 */
void	execute_commands(t_prog *shell)
{
	int	i;

	set_commands(shell);
	pipe_split(shell);
	i = 0;
	while (shell->user_inputs[i] && ft_strcmp("|", shell->user_inputs[i]))
		i++;
	if (!ft_strcmp("|", shell->user_inputs[i]))
	{
		shell->user_inputs = realloc_back(shell->user_inputs, "|");
		shell->user_inputs = realloc_back(shell->user_inputs,
				shell->user_inputs[1]);
	}
	i = 0;
	free(shell->commands);
}

/**
 * @brief	Checks if there are any pipes in the list of user inputs. If there
 * are, it will set the first list of arguments to be executed. Otherwise,
 * it will excecute the full list.
**/
void	check_pipes(t_prog *shell)
{
	int	i;

	i = 0;
	if (!shell->user_inputs[i])
		exit (0);
	while (shell->user_inputs[i])
	{
		if (!ft_strcmp(">", shell->user_inputs[i])
			|| !ft_strcmp(">>", shell->user_inputs[i]))
		{
			shell->user_inputs[i] = NULL;
			break ;
		}
		if (!ft_strcmp("|", shell->user_inputs[i]))
		{
			execute_commands(shell);
			i = -1;
		}
		i++;
	}
	shell->commands = shell->user_inputs;
	last_command(shell);
}
