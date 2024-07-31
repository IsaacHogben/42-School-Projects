/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:51:48 by ihogben           #+#    #+#             */
/*   Updated: 2023/08/22 14:51:49 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_program(t_program window)
{
	free(window.mlx);
	exit (0);
}

//onkeydown event,, 53 is the Keycode for ESCAPE
int	key_down(int keycode, t_program window)
{
	if (keycode == 53)
		close_program(window);
	return (0);
}

//event for closing the window with mouse
int	close_button(t_program window)
{
	close_program(window);
	return (0);
}
