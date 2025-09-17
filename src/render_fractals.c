#include "fractol.h"

void	render_complex_fractals(t_fractal *f)
{
	int			x;
	int			y;
	int			iterations;
	t_complex	c;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			c = map_pixel_to_complex(x, y, f);
			if (ft_strcmp(f->name, "julia") == 0)
				iterations = calculate_julia(f, c.r, c.i);
			else if (ft_strcmp(f->name, "mandelbrot") == 0)
				iterations = calculate_mandelbrot(c.r, c.i);
			else
				iterations = calculate_burning_ship(c.r, c.i);
			my_pixel_put(&f->img, x, y, get_color(iterations, f));
		}
	}
}
