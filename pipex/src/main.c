/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:44:07 by ihogben           #+#    #+#             */
/*   Updated: 2023/09/14 14:44:10 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

/*In the child process:
infile is set by opening arg 1, the infile.
infile becomes the standard input. fd[1] becomes the standard output.
The read end of our fd (fd[0]) is closed.
Then the cmd given at arg[2] is executed*/
void	child_process(char **argv, char **envp, int *fd)
{
	int	infile;

	infile = open(argv[1], O_RDONLY, 0777);
	if (infile == -1)
		error("Error opening in file");
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	execute(argv[2], envp);
}

/*In the parent process:
outfile is set by opening arg 4, the outfile.
	The opened file is write-only, created if not existing 
	and will overwrite contents.
fd[0] from our file descriptors becomes the standard input.
outfile becomes the standard output.
The write file of our fd (fd[0]) is closed.
Then the cmd given at arg[3] is executed*/
void	parent_process(char **argv, char **envp, int *fd)
{
	int	outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		error("Error opening out file");
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	execute(argv[3], envp);
}

/*First checks if the correct number of arguments is given
Create pipe
Create fork
The child will run the child process
Then the calling function will wait for the child using waitpid
Then the parent process will run
Both processes end the program when the execute function calls execve*/
int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
		error("Bad Arguments, try: ./pipex <file1> <cmd1> <cmd2> <file2>");
	else
	{
		if (pipe(fd) == -1)
			error("Pipe failed");
		pid = fork();
		if (pid == -1)
			error("Fork failed");
		if (pid == 0)
			child_process(argv, envp, fd);
		waitpid(pid, NULL, 0);
		parent_process(argv, envp, fd);
	}
	return (0);
}
