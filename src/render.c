/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcacere <alcacere@student42madrid.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 09:35:14 by alcacere          #+#    #+#             */
/*   Updated: 2025/09/18 09:35:16 by alcacere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

t_complex	map_pixel_to_complex(int x, int y, t_fractal *f)
{
	t_complex	c;
	double		range;

	range = 4.0 / f->zoom;
	c.r = f->offset_x + ((double)x / WIDTH) * range - (range / 2.0);
	c.i = f->offset_y + ((double)y / HEIGHT) * range - (range / 2.0);
	return (c);
}

void	render_fractal(t_fractal *f)
{
	if (ft_strcmp(f->name, "bifurcation") == 0)
		render_bifurcation(f);
	else
		render_complex_fractals(f);
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img.img_ptr, 0, 0);
}
