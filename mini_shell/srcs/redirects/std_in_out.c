/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_in_out.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 11:31:03 by ihogben           #+#    #+#             */
/*   Updated: 2023/11/12 11:31:04 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* @brief   Redirect Standard Output to Overwrite File
*
* This function redirects the standard output to overwrite the contents 
* of a specified file. If the file does not exist, it is created. 
* The function then executes the command associated with the output 
* redirection and exits the program with the exit status of the command.
*
* @param   filename  The name of the file to which the standard output is 
* 		   			 redirected.
* @param   shell     Pointer to the shell program structure.
*
* @return  Returns 0 on success. If an error occurs during file access 
*			or creation,
*          it returns the error code from check_file_access().
*/
int	std_output_overwrite(char *filename, t_prog *shell)
{
	int	fd;

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd < 0)
	{
		return (check_file_access(filename));
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	remove_redir(">", shell);
	command(shell);
	normalise_exit();
	exit(g_exit_status);
	return (0);
}

/**
 * @brief   Redirect Standard Output to Append File
 *
 * This function redirects the standard output to append the contents of a
 * specified file. If the file does not exist, it is created. The function then
 * executes the command associated with the output redirection and exits the 
 * program with the exit status of the command.
 *
 * @param   filename    The name of the file to which the standard output is rdr.
 * @param   shell       Pointer to the shell program structure.
 *
 * @return  Returns 0 on success. If an error occurs during file access or cr,
 *          it returns the error code from check_file_access().
 * 
 * example
 *	cat output.txt
 * 	1	test
 * 	echo "testing123" >> output.txt
 * 	vim output.txt
 * 	1	test
 * 	2	testing123
*/
int	std_output_append(char *filename, t_prog *shell)
{
	int		fd;

	fd = open(filename, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd < 0)
		return (check_file_access(filename));
	dup2(fd, STDOUT_FILENO);
	close(fd);
	remove_redir(">>", shell);
	command(shell);
	normalise_exit();
	exit(g_exit_status);
	return (0);
}

/**
 * @brief   Redirect Standard Input from File
 *
 * This function redirects the standard input to read from a specified file. 
 * It checks for errors associated with the input file, performs the redirection,
 * and updates the shell program structure accordingly.
 *
 * @param   filename    The name of the file from which standard input is read.
 * @param   shell       Pointer to the shell program structure.
 *
 * @return  Returns -1 on success. If an error occurs during file access, 
 * it returns the error code from check_file_access(). 
 * The return value -1 signifies the need to adjust the index when handling
 * input redirection in the shell.
 *
 * example
 *  vim	output.txt
 *	1	test
 * 	2	testing123
 * 	wc -l < output.txt
 *	2
*/
int	std_input(char *filename, t_prog *shell)
{
	int		fd;

	error_redir("<", shell);
	fd = open(filename, O_RDONLY, 0644);
	if (fd < 0)
		return (check_file_access(filename));
	dup2(fd, STDIN_FILENO);
	close(fd);
	remove_redir("<", shell);
	return (-1);
}

/**
 * @brief   Redirect Standard Input from Here Document
 *
 * This function redirects the standard input to read from a temporary file 
 * created for a here document. It utilizes the `here_doc` function to 
 * handle user input for the here document and then performs the redirection
 * accordingly.
 *
 * @param   delim   The delimiter indicating the end of the here document.
 * @param   shell   Pointer to the shell program structure.
 *
 * @return  Returns -1 on success. If an error occurs during file access or
 *          temporary file creation, it returns the error code from 
 * 			check_file_access(). The return value -1 signifies the need to 
 * 			adjust the index when 
 * handling
 *          input redirection in the shell.
 *
ls << b
	heredoc> a
	heredoc> b
<ls output of current directory>
*/
int	std_input_delim(char *delim, t_prog *shell)
{
	int		fd;
	int		*sigstatus;

	error_redir("<<", shell);
	fd = open("./.heredoc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		return (check_file_access("./.heredoc_tmp"));
	here_doc(fd, delim);
	sigstatus = heredoc_signal_get();
	free(sigstatus);
	fd = open("./.heredoc_tmp", O_RDONLY, 0644);
	dup2(fd, STDIN_FILENO);
	close(fd);
	remove_redir("<<", shell);
	return (-1);
}

/**
 * @brief   Handle Here Document Input
 *
 * This function reads input from the user for a here document, terminated
 * by a specified delimiter. It signals the end of input when the delimiter
 * is encountered or a heredoc termination signal is received. The input
 * lines are written to the given file descriptor.
 *
 * @param   fd      The file descriptor to write the here document input.
 * @param   delim   The delimiter indicating the end of the here document.
 */
void	here_doc(int fd, char *delim)
{
	char	*line;
	char	*tmp;

	signal(SIGINT, heredoc_handler);
	line = readline("heredoc> ");
	while (line)
	{
		if (!ft_strncmp(line, delim, ft_strlen(delim) + 1) || \
			*(heredoc_signal_get()) == 1)
		{
			close(fd);
			free(line);
			return ;
		}
		tmp = ft_strjoin(line, "\n");
		ft_putstr_fd(tmp, fd);
		free(tmp);
		free(line);
		line = readline("heredoc> ");
	}
	free(tmp);
	free(line);
}
