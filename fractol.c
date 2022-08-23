#include <stdio.h>
#include "fractol.h"

static void	display_fractal(char *type)
{
	complx	center;
	complx	start;
	complx	constant;
	double	unit;
	
	center.r = 0;
	center.i = 0;
	constant.r = -0.8;
	constant.i = 0.156;

	unit = (double) 3 / (double) GRID_SIZE;
	start = find_start(center, unit);
	if (!ft_strncmp(type, "mandelbrot", 10))
		print_mandelbrot(start, unit);
	else if (!ft_strncmp(type, "julia", 5))
		print_julia(start, constant, unit);
}

int	main(int argc, char *argv[])
{
	if (argc < 2)
		ft_printf("Invalid argument\n");
	else
		display_fractal(argv[1]);
}
