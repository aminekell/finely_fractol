/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_mouse_and_keys.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akella <akella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:49:49 by akella            #+#    #+#             */
/*   Updated: 2025/02/23 09:20:37 by akella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/fractol_bonus.h"

void	zoom(t_fractal *fractal, int x, int y, double direction)
{
	double	zoom_level;

	if (!fractal || fractal->zoom <= 0)
		return ;
	zoom_level = exp(direction * 0.20);
	fractal->offset_x += (x / fractal->zoom - x / (fractal->zoom * zoom_level));
	fractal->offset_y += (y / fractal->zoom - y / (fractal->zoom * zoom_level));
	fractal->zoom *= zoom_level;
}

int	key_hook(int key_code, t_fractal *fractal)
{
	if (!fractal)
		return (0);
	if (key_code == ESC)
		exit(0);
	else if (key_code == LEFT)
		fractal->offset_x -= 42 / fractal->zoom;
	else if (key_code == RIGHT)
		fractal->offset_x += 42 / fractal->zoom;
	else if (key_code == UP)
		fractal->offset_y -= 42 / fractal->zoom;
	else if (key_code == DOWN)
		fractal->offset_y += 42 / fractal->zoom;
	else if (key_code == C)
		fractal->color += (255 * 255 * 255) / 100;
	else if (key_code == PLUS)
		fractal->max_iterations += 20;
	else if (key_code == MINUS)
	{
		if (fractal->max_iterations > 50)
			fractal->max_iterations -= 20;
	}
	if (fractal->name)
		draw_fractal(fractal, fractal->name);
	return (0);
}

int	mouse_hook(int mouse_code, int x, int y, t_fractal *fractal)
{
	if (!fractal)
		return (0);
	if (mouse_code == SCROLL_UP)
		zoom(fractal, x, y, 1);
	else if (mouse_code == SCROLL_DOWN)
		zoom(fractal, x, y, -1);
	if (fractal->name)
		draw_fractal(fractal, fractal->name);
	return (0);
}
