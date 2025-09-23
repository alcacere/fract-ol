/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bifurcation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcacere <alcacere@student42madrid.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 09:35:30 by alcacere          #+#    #+#             */
/*   Updated: 2025/09/18 09:35:33 by alcacere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	render_bifurcation(t_fractal *f)
{
	int		x;
	int		y_pixel;
	int		i;
	double	r;
	double	x_n;

	x = -1;
	while (++x < WIDTH)
	{
		r = 2.4 + ((double)x / WIDTH) * (4.0 - 2.4);
		x_n = 0.5;
		i = -1;
		while (++i < 1000)
			x_n = r * x_n * (1 - x_n);
		i = -1;
		while (++i < 500)
		{
			x_n = r * x_n * (1 - x_n);
			y_pixel = (int)((1 - x_n) * HEIGHT);
			my_pixel_put(&f->img, x, y_pixel, 0x00FFFF);
		}
	}
}
