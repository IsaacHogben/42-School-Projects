/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 11:31:03 by ihogben           #+#    #+#             */
/*   Updated: 2023/11/12 11:31:04 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	main_redirect(t_prog *shell)
{
	free_inputs(shell);
	waitpid(shell->pid, &g_exit_status, 0);
}

/**
 * @brief   Check for Redirection in User Inputs
 *
 * This function iterates through the user inputs in the shell program and checks
 * if any redirection operators ('>', '>>', '<', '<<') are present. It returns
 * true if at least one redirection is found, indicating the need for redirection
 * handling in subsequent operations.
 *
 * @param   shell   Pointer to the shell program structure.
 *
 * @return  Returns true if any redirection operator is found in the user inputs,
 *          otherwise returns false.
 */
bool	check_redirect(t_prog *shell)
{
	int	i;

	i = 0;
	while (shell->user_inputs[i])
	{
		if (!ft_strcmp(shell->user_inputs[i], ">")
			|| !ft_strcmp(shell->user_inputs[i], ">>")
			|| !ft_strcmp(shell->user_inputs[i], "<")
			|| !ft_strcmp(shell->user_inputs[i], "<<"))
			return (true);
		i++;
	}
	return (false);
}

/**
 * @brief   Check File Accessibility and Type
 *
 * This function checks the accessibility and type of a file specified by the
 * given path. It uses the stat system call to gather information about the file,
 * and then checks if the file is a directory or if the user has execute
 * permission. It logs appropriate error messages in case of issues.
 *
 * @param   file    The path to the file to be checked.
 *
 * @return  Returns 0 if the file is accessible and not a directory, or an
 *          error code (1) with a corresponding error message logged.
 */
int	check_file_access(char *file)
{
	struct stat	buf;

	if (stat(file, &buf) == 0)
	{
		if (buf.st_mode & S_IFDIR)
		{
			return (log_err(file, ": is a directory", 1));
		}
		else if ((buf.st_mode & S_IXUSR) == 0)
		{
			return (log_err(file, ": permission denied", 1));
		}
	}
	return (log_err(file, ": no such file or directory", 1));
}

/**
 * @brief   Perform Standard Input/Output Redirection and Execute Commands
 *
 * This function handles standard input/output redirection based on the
 * user inputs in the shell program. It forks a child process, performs
 * redirection operations, executes commands, and normalizes the exit status.
 *
 */
void	std_sort(t_prog *shell)
{
	int		i;

	if (!check_redirect(shell))
		return ;
	shell->pid = fork();
	if (!shell->pid)
	{
		i = 0;
		while (shell->user_inputs[i])
		{
			if (ft_strcmp(shell->user_inputs[i], ">") == 0)
				std_output_overwrite(shell->user_inputs[i + 1], shell);
			else if (ft_strcmp(shell->user_inputs[i], ">>") == 0)
				std_output_append(shell->user_inputs[i + 1], shell);
			else if (ft_strcmp(shell->user_inputs[i], "<") == 0)
				i = std_input(shell->user_inputs[i + 1], shell);
			else if (ft_strcmp(shell->user_inputs[i], "<<") == 0)
				i = std_input_delim(shell->user_inputs[i + 1], shell);
			i++;
		}
		command(shell);
		normalise_exit();
		exit(g_exit_status);
	}
	main_redirect(shell);
}
