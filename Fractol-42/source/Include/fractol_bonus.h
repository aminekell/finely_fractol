/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akella <akella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 03:38:48 by akella            #+#    #+#             */
/*   Updated: 2025/02/23 09:20:55 by akella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "mlx.h"
# include <math.h>

# define SIZE 700
# define THREAD_WIDTH 7
# define THREAD_NUMBER 100
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define C 8
# define PLUS 24
# define MINUS 27
# define J 38
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

void	put_color_to_pixel(t_fractal *fractal, int x, int y, int colour);
int		exit_fractal(t_fractal *fractal);
double	ft_atof(const char *str);
int		is_valid_float(const char *str);
void	init_fractal(t_fractal *fractal);
void	init_mlx(t_fractal *fractal);
void	calculate_mandelbrot(t_fractal *fractal);
void	calculate_julia(t_fractal *fractal);
void	calculate_tricorn(t_fractal *fractal);
void	*draw_mandelbrot(void *fractal_void);
void	draw_julia(t_fractal *fractal);
void	draw_tricorn(t_fractal *fractal);
int		draw_fractal(t_fractal *fractal, char *query);
int		key_hook(int key_code, t_fractal *fractal);
int		mouse_hook(int mouse_code, int x, int y, t_fractal *fractal);

#endif
