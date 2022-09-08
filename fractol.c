#include <stdio.h>
#include "fractol.h"

static void	initialize_fractal(int argc, char **argv, t_render *render)
{
	if (argc < 2)
	{
		ft_printf("Invalid argument\n");
		exit (0);
	}
	render->center.r = 0;
	render->center.i = 0;
	render->type = argv[1];
	render->constant.r = -0.8;
	render->constant.i = 0.156;
	render->zoom = 1;
	render->max_iterations = 500;
	render->printed = 0;
	render->color = get_color_array(render->max_iterations);
	(void) argv;
}

int	render_next_frame(t_info *info)
{
	if (info->render->printed == 0)
	{
		t_img		img;

		info->img = &img;
		initialize_image(info);
		draw_fractal(info);
		mlx_put_image_to_window(info->vars->mlx, info->vars->win, info->img->img, 0, 0);
		info->render->printed = 1;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_vars		vars;
	t_render	render;
	t_info		info;

	info.vars = &vars;
	info.render = &render;
	initialize_fractal(argc, argv, info.render);
	initialize_window(&info);
//	draw_fractal(&info);
//	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop_hook(vars.mlx, render_next_frame, &info);
	mlx_loop(vars.mlx);
}
