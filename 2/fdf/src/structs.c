/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:08:38 by ihogben           #+#    #+#             */
/*   Updated: 2023/08/22 16:08:39 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	new_map(int x, int y, t_point **point_array)
{
	int		xi;
	int		yi;
	t_map	map;

	xi = 0;
	yi = 0;
	map.x = x;
	map.y = y;
	map.point_array = point_array;
	while (yi < y)
	{
		while (xi < x)
		{
			if (map.max_height < point_array[xi][yi].height)
				map.max_height = point_array[xi][yi].height;
			else if (map.min_height > point_array[xi][yi].height)
				map.min_height = point_array[xi][yi].height;
			xi++;
		}
		xi = 0;
		yi++;
	}
	map.height_range = map.max_height - map.min_height;
	return (map);
}

t_point	new_point(int x, int y, char *height)
{
	t_point	point;
	int		i;

	i = 0;
	point.x = x;
	point.y = y;
	while (height[i])
	{
		if (height[i] == ',')
		{
			height[i] = '\0';
		}
		i++;
	}
	point.height = ft_atoi(height);
	return (point);
}

t_point	cpy_point(t_point p)
{
	t_point	point;

	point.x = p.x;
	point.y = p.y;
	point.height = p.height;
	return (point);
}
