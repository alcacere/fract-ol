/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcacere <alcacere@student42madrid.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 09:36:19 by alcacere          #+#    #+#             */
/*   Updated: 2025/09/19 11:16:42 by alcacere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	arg_error(void)
{
	ft_putendl_fd("Usage:", 1);
	ft_putendl_fd("  ./fractol mandelbrot", 1);
	ft_putendl_fd("  ./fractol burning_ship", 1);
	ft_putendl_fd("  ./fractol julia <real> <imaginary>", 1);
	ft_putendl_fd("  ./fractol bifurcation", 1);
	exit(EXIT_FAILURE);
}

int	close_handler(t_fractal *f)
{
	mlx_destroy_image(f->mlx_ptr, f->img.img_ptr);
	mlx_destroy_window(f->mlx_ptr, f->win_ptr);
	free(f->mlx_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}
