#include "fractol.h"

void	arg_error(void)
{
	ft_putendl_fd("Usage:\n", 1);
	ft_putendl_fd("  ./fractol mandelbrot\n", 1);
	ft_putendl_fd("  ./fractol burning_ship\n", 1);
	ft_putendl_fd("  ./fractol julia <real> <imaginary>", 1);
	ft_putendl_fd("And also, for evaluation sake, use: ./fractol bifurcation", 1);
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
