/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akella <akella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 03:23:40 by akella            #+#    #+#             */
/*   Updated: 2025/02/23 09:17:53 by akella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "mlx.h"
# include <math.h>

# define SIZE 600
# define ESC 53
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_fractal
{
	void	*mlx;
	void	*window;
	void	*image;
	void	*pointer_to_image;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	int		color;
	double	offset_x;
	double	offset_y;
	double	zoom;
	char	*name;
	int		max_iterations;
}	t_fractal;

void	put_color_to_pixel(t_fractal *fractal, int x, int y, int iterations);
int		exit_fractal(t_fractal *fractal);
void	init_fractal(t_fractal *fractal);
void	init_mlx(t_fractal *fractal);
void	calculate_mandelbrot(t_fractal *fractal);
void	calculate_julia(t_fractal *fractal);
int		draw_fractal(t_fractal *fractal, char *query);
int		key_hook(int key_code, t_fractal *fractal);
int		mouse_hook(int mouse_code, int x, int y, t_fractal *fractal);
void	*draw_mandelbrot(void *fractal_void);
void	draw_julia(t_fractal *fractal);
double	ft_atof(const char *str);
int		is_valid_float(const char *str);
void	put_color_to_pixel(t_fractal *fractal, int x, int y, int color);

#endif