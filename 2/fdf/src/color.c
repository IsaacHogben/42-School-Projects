/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:41:57 by ihogben           #+#    #+#             */
/*   Updated: 2023/08/22 12:41:58 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	blend_colors(int color1, int color2, float scale)
{
	t_rgb	start;
	t_rgb	end;
	t_rgb	result;

	start.r = (color1 >> 16) & 0xFF;
	start.g = (color1 >> 8) & 0xFF;
	start.b = color1 & 0xFF;
	end.r = (color2 >> 16) & 0xFF;
	end.g = (color2 >> 8) & 0xFF;
	end.b = color2 & 0xFF;
	result.r = start.r + (end.r - start.r) * scale;
	result.g = start.g + (end.g - start.g) * scale;
	result.b = start.b + (end.b - start.b) * scale;
	return ((result.r << 16) | (result.g << 8) | result.b);
}

int	scale_to_int(float scale)
{
	if (scale <= 25)
		return (blend_colors(COLOR_1, COLOR_2, scale / 25));
	else if (scale <= 50)
		return (blend_colors(COLOR_2, COLOR_3, (scale - 25) / 25));
	else if (scale <= 75)
		return (blend_colors(COLOR_3, COLOR_4, (scale - 50) / 25));
	else
		return (blend_colors(COLOR_4, COLOR_5, (scale - 75) / 25));
}

float	get_point_color_scale(t_point point, t_map map)
{
	float	color_scale;

	color_scale = (float)(point.height - map.min_height) 
		/ (float)(map.max_height - map.min_height);
	color_scale = color_scale * 100;
	return (color_scale);
}

int	get_pixel_color(t_point end, t_point start, float cratio, t_map map)
{
	float	start_color;
	float	end_color;
	float	pixel_color;

	start_color = get_point_color_scale(start, map);
	end_color = get_point_color_scale(end, map);
	pixel_color = ((end_color - start_color) * cratio) + start_color;
	return (scale_to_int(pixel_color));
}

//convert 3 doubles to a bit int
int	rgb_to_int(double r, double g, double b)
{
	int	color;

	color = 0;
	color |= (int)(b * 255);
	color |= (int)(g * 255) << 8;
	color |= (int)(r * 255) << 16;
	return (color);
}
