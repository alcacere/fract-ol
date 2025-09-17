#include "fractol.h"

static void	setup_hooks(t_fractal *f)
{
	mlx_key_hook(f->win_ptr, key_handler, f);
	mlx_hook(f->win_ptr, 17, 0, close_handler, f);
	mlx_mouse_hook(f->win_ptr, mouse_handler, f);
	mlx_hook(f->win_ptr, 6, (1L<<6), mouse_motion_handler, f);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (argc < 2)
		arg_error();
	fractal_init(&fractal, argc, argv);
	render_fractal(&fractal);
	setup_hooks(&fractal);
	mlx_loop(fractal.mlx_ptr);
	return (0);
}
