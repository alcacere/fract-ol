#include "fractol.h"

int	calculate_mandelbrot(double c_r, double c_i)
{
	int		i;
	double	z_r;
	double	z_i;
	double	tmp;

	i = 0;
	z_r = 0.0;
	z_i = 0.0;
	while (z_r * z_r + z_i * z_i < 4 && i < MAX_ITERATIONS)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + c_r;
		z_i = 2 * tmp * z_i + c_i;
		i++;
	}
	return (i);
}

int	calculate_julia(t_fractal *f, double z_r, double z_i)
{
	int		i;
	double	tmp;

	i = 0;
	while (z_r * z_r + z_i * z_i < 4 && i < MAX_ITERATIONS)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + f->julia_c_r;
		z_i = 2 * tmp * z_i + f->julia_c_i;
		i++;
	}
	return (i);
}

int	calculate_burning_ship(double c_r, double c_i)
{
	int		i;
	double	z_r;
	double	z_i;
	double	tmp;

	i = 0;
	z_r = 0.0;
	z_i = 0.0;
	while (z_r * z_r + z_i * z_i < 4 && i < MAX_ITERATIONS)
	{
		z_r = fabs(z_r);
		z_i = fabs(z_i);
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + c_r;
		z_i = 2 * tmp * z_i + c_i;
		i++;
	}
	return (i);
}
