#include <stdio.h>
#include "fractol.h"

static void	initialize_fractal(int argc, char **argv, t_render *fractal)
{
	if (argc < 2)
	{
		ft_printf("Invalid argument\n");
		exit (0);
	}
	fractal->center.r = 0;
	fractal->center.i = 0;
	fractal->type = argv[1];
	fractal->constant.r = -0.7269;
	fractal->constant.i = 0.1889;
	fractal->zoom = 1;
	fractal->max_iterations = 500;
	fractal->printed = 0;
	(void) argv;
}

int	render_next_frame(t_info *info)
{
	if (info->render->printed == 0)
	{
		draw_fractal(info);
		mlx_put_image_to_window(info->vars->mlx, info->vars->win, info->img->img, 0, 0);
		info->render->printed = 1;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_vars		vars;
	t_img		img;
	t_render	render;
	t_info		info;

	info.vars = &vars;
	info.render = &render;
	info.img = &img;
	initialize_fractal(argc, argv, info.render);
	initialize_window(&info);
//	draw_fractal(&info);
//	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop_hook(vars.mlx, render_next_frame, &info);
	mlx_loop(vars.mlx);

}
