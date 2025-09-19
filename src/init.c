/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcacere <alcacere@student42madrid.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 09:34:46 by alcacere          #+#    #+#             */
/*   Updated: 2025/09/19 13:34:35 by alcacere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

static void	parse_julia_args(t_fractal *f, int argc, char **argv)
{
	if (argc != 4)
		arg_error();
	f->julia_c_r = ft_atod(argv[2]);
	f->julia_c_i = ft_atod(argv[3]);
}

static void	init_data(t_fractal *f, int argc, char **argv)
{
	f->name = argv[1];
	f->zoom = 1.0;
	f->offset_x = 0.0;
	f->offset_y = 0.0;
	f->color_scheme = 0;
	f->locked_julia = 1;
	f->m_i = MAX_ITERATIONS;
	if (ft_strcmp(f->name, "mandelbrot") == 0 && argc == 2)
		return ;
	else if (ft_strcmp(f->name, "burning_ship") == 0 && argc == 2)
		return ;
	else if (ft_strcmp(f->name, "bifurcation") == 0)
		return ;
	else if (ft_strcmp(f->name, "julia") == 0)
		parse_julia_args(f, argc, argv);
	else
		arg_error();
}

void	init_mlx(t_fractal *f)
{
	f->mlx_ptr = mlx_init();
	f->win_ptr = mlx_new_window(f->mlx_ptr, WIDTH, HEIGHT, "Fract-ol");
	f->img.img_ptr = mlx_new_image(f->mlx_ptr, WIDTH, HEIGHT);
	f->img.addr = mlx_get_data_addr(f->img.img_ptr, &f->img.bpp,
			&f->img.line_length, &f->img.endian);
}

void	fractal_init(t_fractal *f, int argc, char **argv)
{
	init_data(f, argc, argv);
	init_mlx(f);
}
