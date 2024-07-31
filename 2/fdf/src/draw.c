/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:25:11 by ihogben           #+#    #+#             */
/*   Updated: 2023/08/22 15:25:14 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

int	get_color(t_point start, t_point end, int pixels, t_map map)
{
	static int	total_pixels;
	static int	p;
	float		cratio;

	if (p < pixels)
		total_pixels = pixels;
	p = pixels;
	cratio = (float)p / (float)total_pixels;
	return (get_pixel_color(start, end, cratio, map));
}

int	draw_line(t_program window, t_map map, t_point start, t_point end)
{
	double	delta_x;
	double	delta_y;
	double	pixel_x;
	double	pixel_y;
	int		pixels;

	delta_x = end.x - start.x;
	delta_y = end.y - start.y;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	pixel_x = start.x;
	pixel_y = start.y;
	while (pixels)
	{
		img_pix_put(&window.image, pixel_x, pixel_y, 
			(get_color(start, end, pixels, map)));
		pixel_x += delta_x;
		pixel_y += delta_y;
		pixels--;
	}
	return (0);
}

int	create_terrain(t_program window, t_map map)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	translate_points(map);
	while (y < map.y)
	{
		while (x < map.x)
		{
			if (x != map.x - 1)
				draw_line(window, map, map.point_array[x][y], 
					map.point_array[x + 1][y]);
			if (y != map.y - 1)
				draw_line(window, map, map.point_array[x][y], 
					map.point_array[x][y + 1]);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
