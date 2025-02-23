/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_tricorn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akella <akella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 10:53:00 by akella            #+#    #+#             */
/*   Updated: 2025/02/22 07:46:22 by akella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/fractol_bonus.h"

static void	initialize_tricorn(t_fractal *fractal, int *i,
		double *escape_radius)
{
	fractal->name = "tricorn";
	*escape_radius = 4.0;
	fractal->zx = 0.0;
	fractal->zy = 0.0;
	fractal->cx = (fractal->x / fractal->zoom) + fractal->offset_x;
	fractal->cy = (fractal->y / fractal->zoom) + fractal->offset_y;
	*i = 0;
}

static int	iterate_tricorn(t_fractal *fractal, double escape_radius)
{
	int		i;
	double	x_temp;

	initialize_tricorn(fractal, &i, &escape_radius);
	while (++i < fractal->max_iterations)
	{
		x_temp = fractal->zx * fractal->zx
			- fractal->zy * fractal->zy + fractal->cx;
		fractal->zy = -2.0 * fractal->zx * fractal->zy + fractal->cy;
		fractal->zx = x_temp;
		if ((fractal->zx * fractal->zx + fractal->zy * fractal->zy)
			>= escape_radius)
			break ;
	}
	return (i);
}

void	calculate_tricorn(t_fractal *fractal)
{
	int		i;
	double	escape_radius;

	escape_radius = 4.0;
	if (!fractal || !fractal->mlx || !fractal->window || !fractal->image)
		return ;
	i = iterate_tricorn(fractal, escape_radius);
	if (i == fractal->max_iterations)
		put_color_to_pixel(fractal, fractal->x, fractal->y, 0x000000);
	else
		put_color_to_pixel(fractal, fractal->x, fractal->y,
			fractal->color * (i % 255));
}
