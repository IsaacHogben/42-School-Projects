/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:35:42 by ihogben           #+#    #+#             */
/*   Updated: 2023/09/18 15:35:43 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	error(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

/*Find 'PATH' in the environment variables
split everything after path with :
Step through each directory in the path until we find the cmd and have access
	When found return that path, otherwise we free strings and return 0;*/
char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (0);
}

/*The argument is split in the case of a cmd with a given arg i.e "wc -l"
use the find_path function to seach for the first value in the given arguments
find_path will return 0 if no cmd is found
	if this is the case we need to free all mallocs
else we can execve the cmd*/
void	execute(char *arg, char **envp)
{
	char	**cmd;
	int		i;
	char	*path;

	i = -1;
	cmd = ft_split(arg, ' ');
	path = find_path(cmd[0], envp);
	printf("%s\n", path);
	if (!path)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		error("Error finding command path");
	}
	if (execve(path, cmd, envp) == -1)
		error("excve Error");
}
