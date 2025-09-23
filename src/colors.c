/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcacere <alcacere@student42madrid.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 09:34:04 by alcacere          #+#    #+#             */
/*   Updated: 2025/09/19 13:38:17 by alcacere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

static int	lerp(int start, int end, double t)
{
	return ((int)(start + (end - start) * t));
}

static int	gradient_color(int iter, int start, int end, t_fractal *f)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)iter / f->m_i;
	r = lerp((start >> 16) & 0xFF, (end >> 16) & 0xFF, t);
	g = lerp((start >> 8) & 0xFF, (end >> 8) & 0xFF, t);
	b = lerp(start & 0xFF, end & 0xFF, t);
	return ((r << 16) | (g << 8) | b);
}

int	get_color(int iterations, t_fractal *f)
{
	int	color;

	if (iterations == f->m_i)
		return (0x0a0a0a);
	if (f->color_scheme == 0)
		color = gradient_color(iterations, 0x2c142c, 0x7a1b0c, f);
	else if (f->color_scheme == 1)
		color = (iterations * 0x04080F) ^ 0x123456;
	else
		color = gradient_color(iterations, 0x370617, 0xe85d04, f);
	return (color);
}
