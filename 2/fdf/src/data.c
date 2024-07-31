/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:11:25 by ihogben           #+#    #+#             */
/*   Updated: 2023/08/23 13:11:26 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//get the size of the map
void	get_map_size(int *x, int *y, char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] != ' ' && map[i] != '\n' && map[i] != '\0' && *y == 0)
		{
			*x = *x + 1;
			while (map[i] != ' ')
				i++;
		}
		else if (map[i] == '\n')
			*y = *y + 1;
		i++;
	}
}

//creats the point array.
t_point	**make_points(int rows, int columns, char **data)
{
	int		x;
	int		y;
	int		i;
	t_point	**point_array;

	x = 0;
	y = 0;
	i = 0;
	point_array = (t_point **)malloc(rows * sizeof(t_point *));
	while (i < rows)
		point_array[i++] = (t_point *)malloc(columns * sizeof(t_point));
	if (!point_array)
		return (NULL);
	i = 0;
	while (y < columns)
	{
		while (x < rows)
		{
			point_array[x][y] = new_point(x, y, data[i++]);
			x++;
		}
		x = 0;
		y++;
	}
	return (point_array);
}

//Corrects map files that do not follow the format
//where there is no space at the end of a line we add one.
char	*format_string(char *str)
{
	int		i;
	char	*fstr;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			if (str[i - 1] != ' ')
			{
				fstr = malloc(sizeof(char) * (ft_strlen(str) + 1));
				if (!fstr)
					return (NULL);
				ft_strlcpy(fstr, str, strlen(str));
				fstr[i] = ' ';
				fstr[i + 1] = '\n';
				fstr[i + 2] = '\0';
				free(str);
				return (fstr);
			}
		}
		i++;
	}
	return (str);
}

//turns our map string into a point array and 
//gets the x and y values of the map, stored in the t_map.
t_map	parse_map(char *map_str)
{
	int		x;
	int		y;
	char	**data;
	t_map	map;

	x = 0;
	y = 0;
	get_map_size(&x, &y, map_str);
	ft_putnbr_fd(x, 0);
	ft_putchar_fd(',', 0);
	ft_putnbr_fd(y, 0);
	ft_putchar_fd('\n', 0);
	data = ft_split(map_str, ' ');
	map = new_map(x, y, make_points(x, y, data));
	ft_free_split(data);
	return (map);
}

//open and read the map file, converting it into a string and 
//translating the data.
t_map	read_map(char *file)
{
	int		fd;
	char	*map_str;
	char	*temp;
	t_map	map;

	map_str = NULL;
	fd = open(file, O_RDONLY);
	temp = get_next_line(fd);
	while (temp != NULL)
	{
		temp = format_string(temp);
		map_str = ft_strjoin(map_str, temp);
		free(temp);
		temp = get_next_line(fd);
	}
	map = parse_map(map_str);
	free(map_str);
	return (map);
}
