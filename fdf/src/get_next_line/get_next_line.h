/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:24:19 by ihogben           #+#    #+#             */
/*   Updated: 2023/08/02 12:24:25 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*ft_add_read_line(int fd, char *read_lines);
char	*ft_get_line(char *read_lines);
char	*ft_get_new_read_line(char *left_str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *read_lines, char *buff);
size_t	ft_strlen(char *s);

#endif
