/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:40:00 by ihogben           #+#    #+#             */
/*   Updated: 2023/08/08 12:40:01 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_add_read_line(int fd, char *read_line)
{
	char	*buffer;
	int		read_bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(read_line, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		read_line = ft_strjoin(read_line, buffer);
	}
	free(buffer);
	return (read_line);
}

char	*ft_get_line(char *read_line)
{
	int		i;
	char	*str;

	i = 0;
	if (!read_line[i])
		return (NULL);
	while (read_line[i] && read_line[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (read_line[i] && read_line[i] != '\n')
	{
		str[i] = read_line[i];
		i++;
	}
	if (read_line[i] == '\n')
	{
		str[i] = read_line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_get_new_read_line(char *read_line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (read_line[i] && read_line[i] != '\n')
		i++;
	if (!read_line[i])
	{
		free(read_line);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(read_line) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (read_line[i])
		str[j++] = read_line[i++];
	str[j] = '\0';
	free(read_line);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*read_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0))
	{
		if (read_line)
			free(read_line);
		read_line = NULL;
		return (0);
	}
	read_line = ft_add_read_line(fd, read_line);
	if (!read_line)
		return (NULL);
	line = ft_get_line(read_line);
	read_line = ft_get_new_read_line(read_line);
	return (line);
}
