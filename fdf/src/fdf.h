/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:44:09 by ihogben           #+#    #+#             */
/*   Updated: 2023/08/22 12:44:12 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
//# include "./get_next_line/get_next_line.h"
# include <math.h>
# include <fcntl.h>

# define X_WINDOW_SIZE	2100
# define Y_WINDOW_SIZE	1200
# define IMAGE_SCALE	1250
# define ROTATION_VALUE	40
# define VIEWING_ANGLE	33
# define HEIGHT_SCALE	25
//# define COLOR_1		0x082114
//# define COLOR_2		0x1e441e
//# define COLOR_3		0x2a7221
//# define COLOR_4		0x119822
//# define COLOR_5		0xaeee95
//# define COLOR_1		0x0C0C0C
//# define COLOR_2		0xBA5A31
//# define COLOR_3		0xE59F71
//# define COLOR_4		0x69DC9E
//# define COLOR_5		0xFFFFFF
# define COLOR_1		0x14342B
# define COLOR_2		0x60935D
# define COLOR_3		0xBAB700
# define COLOR_4		0xBBDFC5
# define COLOR_5		0xFF579F
//mlx image
typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;
//Program struct holds the data for the mlx window instance
typedef struct s_program
{
	void	*mlx;
	void	*win;
	t_img	image;
}	t_program;
//point holds x and y value of the pixel to be displayed, along 
//with the corrosponding height value.
typedef struct s_point
{
	double		x;
	double		y;
	float		height;
	int			color;
}	t_point;
//holds relavent data for the map including the array of points 
//and the total x and y values.
typedef struct s_map
{
	struct s_point	**point_array;
	int				x;
	int				y;
	int				min_height;
	int				max_height;
	int				height_range;
}	t_map;
//an rgb value struct
typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

int		rgb_to_int(double r, double g, double b);
int		key_down(int keycode, t_program instance);
int		close_button(t_program instance);
t_point	new_point(int x, int y, char *height);
t_point	cpy_point(t_point p);
char	*get_next_line(int fd);
t_map	read_map(char *file);
int		create_terrain(t_program window, t_map map);
int		translate_points(t_map map);
t_map	new_map(int x, int y, t_point **point_array);
int		get_pixel_color(t_point start, t_point end, float cratio, t_map map);
int		get_point_color(t_point point, t_map map);

#endif