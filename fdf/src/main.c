/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:05:05 by ihogben           #+#    #+#             */
/*   Updated: 2023/08/21 15:05:06 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_program	create_window(void)
{
	t_program	window;

	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, X_WINDOW_SIZE, Y_WINDOW_SIZE, 
			"Window");
	window.image.mlx_img = mlx_new_image(window.mlx, X_WINDOW_SIZE, 
			Y_WINDOW_SIZE);
	window.image.addr = mlx_get_data_addr(window.image.mlx_img, 
			&window.image.bpp, &window.image.line_len, &window.image.endian);
	return (window);
}

int	main(int argc, char **argv)
{
	t_program	window;
	t_map		map;

	if (argc != 2)
	{
		ft_putstr_fd("Give file", 0);
		return (1);
	}
	map = read_map(argv[1]);
	window = create_window();
	mlx_hook(window.win, 2, 1L << 0, key_down, &window);
	mlx_hook(window.win, 17, 0, close_button, &window);
	create_terrain(window, map);
	mlx_put_image_to_window(window.mlx, window.win, window.image.mlx_img, 0, 0);
	mlx_loop(window.mlx);
	return (0);
}
