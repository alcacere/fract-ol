#include "fractol.h"

static int	lerp(int start, int end, double t)
{
	return ((int)(start + (end - start) * t));
}

static int	gradient_color(int iterations, int start_color, int end_color)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)iterations / MAX_ITERATIONS;
	r = lerp((start_color >> 16) & 0xFF, (end_color >> 16) & 0xFF, t);
	g = lerp((start_color >> 8) & 0xFF, (end_color >> 8) & 0xFF, t);
	b = lerp(start_color & 0xFF, end_color & 0xFF, t);
	return ((r << 16) | (g << 8) | b);
}

int	get_color(int iterations, t_fractal *f)
{
	int	color;

	if (iterations == MAX_ITERATIONS)
		return (0x000000);
	if (f->color_scheme == 0)
		color = gradient_color(iterations, 0x190D3A, 0x00BEFF);
	else if (f->color_scheme == 1)
		color = (iterations * 0x04080F) ^ 0x123456;
	else
		color = gradient_color(iterations, 0xFFFFFF, 0x000000);
	return (color);
}
