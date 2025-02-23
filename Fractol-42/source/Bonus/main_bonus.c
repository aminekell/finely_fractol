/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akella <akella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+        */
/*   Created: 2025/02/14 21:49:49 by akella            #+#    #+#             */
/*   Updated: 2025/02/21 02:45:34 by akella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/fractol_bonus.h"

static void	print_usage(void)
{
	ft_printf("Usage: ./fractol [mandelbrot] || [julia] || [tricorn]\n");
	ft_printf("\nAvailable fractals: [mandelbrot] && [julia] && [tricorn]\n");
	exit(1);
}

static void	validate_julia_args(int argc, char **argv)
{
	if (argc != 4)
	{
		ft_printf("\nError: Julia requires two float parameters (cx, cy).\n");
		exit(1);
	}
	if (!is_valid_float(argv[2]) || !is_valid_float(argv[3]))
	{
		ft_printf("\nError: Julia parameters must be valid float numbers.\n");
		exit(1);
	}
}

static void	check_args(int argc, char **argv)
{
	if (argc < 2 || argc > 4)
		print_usage();
	if (ft_strncmp(argv[1], "mandelbrot", 10) != 0
		&& ft_strncmp(argv[1], "julia", 5) != 0
		&& ft_strncmp(argv[1], "tricorn", 7) != 0)
	{
		ft_printf("\nError: Invalid fractal type.\n");
		print_usage();
	}
	if (ft_strncmp(argv[1], "julia", 5) == 0)
		validate_julia_args(argc, argv);
}

static void	setup_hooks(t_fractal *fractal)
{
	mlx_key_hook(fractal->window, key_hook, fractal);
	mlx_mouse_hook(fractal->window, mouse_hook, fractal);
	mlx_hook(fractal->window, 17, 0L, exit_fractal, fractal);
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	check_args(argc, argv);
	fractal = malloc(sizeof(t_fractal));
	if (!fractal)
	{
		ft_printf("Error: Memory allocation failed.\n");
		return (1);
	}
	init_fractal(fractal);
	init_mlx(fractal);
	if (ft_strncmp(argv[1], "julia", 5) == 0)
	{
		fractal->cx = ft_atof(argv[2]);
		fractal->cy = ft_atof(argv[3]);
	}
	setup_hooks(fractal);
	draw_fractal(fractal, argv[1]);
	mlx_loop(fractal->mlx);
	return (0);
}
