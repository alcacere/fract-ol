#include "fractol.h"

static void	handle_complex_move(int keycode, t_fractal *f)
{
	double	move_step;

	move_step = 0.2 / f->zoom;
	if (keycode == KEY_UP)
		f->offset_y -= move_step;
	else if (keycode == KEY_DOWN)
		f->offset_y += move_step;
	else if (keycode == KEY_LEFT)
		f->offset_x -= move_step;
	else if (keycode == KEY_RIGHT)
		f->offset_x += move_step;
}

int	key_handler(int keycode, t_fractal *f)
{
	if (keycode == KEY_ESC)
		close_handler(f);
	else if (keycode == KEY_C)
		f->color_scheme = (f->color_scheme + 1) % 3;
	handle_complex_move(keycode, f);
	render_fractal(f);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *f)
{
	double	zoom_factor;

	if (button == MOUSE_WHEEL_UP || button == MOUSE_WHEEL_DOWN)
	{
		zoom_factor = (button == MOUSE_WHEEL_UP) ? 0.9 : 1.1;
		t_complex	mouse_b4 = map_pixel_to_complex(x, y, f);
		f->zoom /= zoom_factor;
		t_complex	mouse_after = map_pixel_to_complex(x, y, f);
		f->offset_x += mouse_b4.r - mouse_after.r;
		f->offset_y += mouse_b4.i - mouse_after.i;
	}
	else if (button == MOUSE_RIGHT_CLICK)
	{
		if (ft_strncmp(f->name, "julia", 5) == 0)
			f->locked_julia = !f->locked_julia;
	}
	render_fractal(f);
	return (0);
}

int	mouse_motion_handler(int x, int y, t_fractal *f)
{
	t_complex	c;

	if (ft_strncmp(f->name, "julia", 5) == 0 && !f->locked_julia)
	{
		c = map_pixel_to_complex(x, y, f);
		f->julia_c_r = c.r;
		f->julia_c_i = c.i;
		render_fractal(f);
	}
	return (0);
}
