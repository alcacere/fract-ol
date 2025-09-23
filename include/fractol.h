/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcacere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 10:05:46 by alcacere          #+#    #+#             */
/*   Updated: 2025/09/19 14:54:52 by alcacere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "libft.h"
# include "../minilibx-linux/mlx.h"

# define WIDTH 1000
# define HEIGHT 1000
# define MAX_ITERATIONS 100

# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_C 99
# define KEY_R 114
# define KEY_U 117
# define KEY_D 100

# define MOUSE_RIGHT_CLICK 3
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

typedef struct s_fractal
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	char		*name;
	double		zoom;
	double		offset_x;
	double		offset_y;
	double		julia_c_r;
	double		julia_c_i;
	int			locked_julia;
	int			color_scheme;
	int			m_i;
}	t_fractal;

int			get_color(int iterations, t_fractal *f);
void		fractal_init(t_fractal *f, int argc, char **argv);

void		render_fractal(t_fractal *f);
t_complex	map_pixel_to_complex(int x, int y, t_fractal *f);
void		render_bifurcation(t_fractal *f);
void		render_complex_fractals(t_fractal *f);
void		my_pixel_put(t_img *img, int x, int y, int color);
void		key_iteration_handler(int keycode, t_fractal *f);

int			calculate_mandelbrot(double c_r, double c_i, int m_i);
int			calculate_julia(t_fractal *f, double z_r, double z_i, int m_i);
int			calculate_burning_ship(double c_r, double c_i, int m_i);

int			key_handler(int keycode, t_fractal *f);
int			mouse_handler(int button, int x, int y, t_fractal *f);
int			mouse_motion_handler(int x, int y, t_fractal *f);

void		arg_error(void);
int			close_handler(t_fractal *f);
void		range_error(void);

double		ft_atod(char *str);

#endif
