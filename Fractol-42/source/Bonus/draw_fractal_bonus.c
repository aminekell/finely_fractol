/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akella <akella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 02:44:29 by akella            #+#    #+#             */
/*   Updated: 2025/02/21 02:53:57 by akella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/fractol_bonus.h"

int	draw_fractal(t_fractal *fractal, char *query)
{
	if (!fractal || !query)
		return (1);
	if (ft_strncmp(query, "mandelbrot", 10) == 0)
		draw_mandelbrot(fractal);
	else if (ft_strncmp(query, "julia", 5) == 0)
		draw_julia(fractal);
	else if (ft_strncmp(query, "tricorn", 7) == 0)
		draw_tricorn(fractal);
	else
	{
		ft_printf("\nAvailable fractals: [mandelbrot] && [julia]\n");
		ft_printf("&& [tricorn]\n");
		exit_fractal(fractal);
	}
	if (fractal->mlx && fractal->window && fractal->image)
		mlx_put_image_to_window(fractal->mlx, fractal->window,
			fractal->image, 0, 0);
	return (0);
}
