/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcacere <alcacere@student42madrid.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 09:35:53 by alcacere          #+#    #+#             */
/*   Updated: 2025/09/19 13:26:36 by alcacere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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
				iterations = calculate_julia(f, c.r, c.i, f->m_i);
			else if (ft_strcmp(f->name, "mandelbrot") == 0)
				iterations = calculate_mandelbrot(c.r, c.i, f->m_i);
			else
				iterations = calculate_burning_ship(c.r, c.i, f->m_i);
			my_pixel_put(&f->img, x, y, get_color(iterations, f));
		}
	}
}
