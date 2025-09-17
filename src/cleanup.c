#include "fractol.h"

void	arg_error(void)
{
	int wt;

	wt = write(1, "Please use valid arguments:\n", 28);
	wt += write(1, "  ./fractol mandelbrot\n", 23);
	wt += write(1, "  ./fractol burning_ship\n", 25);
	wt += write(1, "  ./fractol julia <real> <imaginary>\n", 37);
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
