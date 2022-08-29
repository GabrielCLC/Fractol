#include <stdio.h>
#include "fractol.h"

static void	check_arguments(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_printf("Invalid argument\n");
		exit (0);
	}
	(void) argv;
}

int	main(int argc, char *argv[])
{
	t_vars	vars;
	t_data	img;

	check_arguments(argc, argv);
	initialize_window(&vars, &img);
//	draw_fractal(argv[1], &img);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);

	mlx_loop(vars.mlx);

}
