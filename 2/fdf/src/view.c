/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:42:42 by ihogben           #+#    #+#             */
/*   Updated: 2023/08/24 13:42:44 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	scale_point(t_map map, t_point point)
{
	float	scalex;
	float	scaley;
	float	ratio;

	ratio = ((float)map.x - 1) / ((float)map.y - 1);
	if (map.x > map.y)
	{
		scalex = ((float)IMAGE_SCALE / (map.x - 1));
		scaley = ((float)IMAGE_SCALE / (map.y - 1)) / ratio;
		point.x = point.x * scalex - (IMAGE_SCALE / 2);
		point.y = point.y * scaley - (IMAGE_SCALE / 2 / ratio);
	}
	else 
	{
		scalex = ((float)IMAGE_SCALE / (map.x - 1)) * ratio;
		scaley = ((float)IMAGE_SCALE / (map.y - 1));
		point.x = point.x * scalex - (IMAGE_SCALE / 2 * ratio);
		point.y = point.y * scaley - (IMAGE_SCALE / 2);
	}
	return (point);
}

t_point	rotate_point(t_point point)
{
	float	newx;
	float	newy;
	float	angle;	

	angle = (float)ROTATION_VALUE * (M_PI / 180);
	newx = (point.x * cos(angle)) - (point.y * sin(angle));
	newy = (point.y * cos(angle)) + (point.x * sin(angle));
	point.x = newx;
	point.y = newy * ((float)VIEWING_ANGLE / 90);
	return (point);
}

t_point	center_point(t_map map, t_point point)
{
	float	image_ratio;

	image_ratio = ((float)map.x - 1) / ((float)map.y - 1);
	point.x = point.x + (X_WINDOW_SIZE / 2);
	point.y = point.y + (Y_WINDOW_SIZE / 2);
	return (point);
}

t_point	raise_point(t_map map, t_point point)
{
	float	height_scale;
	float	image_scale;

	height_scale = ((float)HEIGHT_SCALE * 10 / (float)map.height_range);
	image_scale = (float)IMAGE_SCALE / (float)Y_WINDOW_SIZE;
	point.y -= point.height * (1 - ((float)VIEWING_ANGLE / 90))
		* height_scale * image_scale;
	return (point);
}

int	translate_points(t_map map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map.y)
	{
		while (x < map.x)
		{
			map.point_array[x][y] = scale_point(map, map.point_array[x][y]);
			map.point_array[x][y] = rotate_point(map.point_array[x][y]);
			map.point_array[x][y] = center_point(map, map.point_array[x][y]);
			map.point_array[x][y] = raise_point(map, map.point_array[x][y]);
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}
