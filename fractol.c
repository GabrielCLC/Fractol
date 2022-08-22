#include <stdio.h>
#include "fractol.h"

int iterate_until_escape(complx constant)
{
	int	i;
	complx	nbr;

	nbr.r = 0;
	nbr.i = 0;
	i = 0;
	while (++i < ITERATION_LIMIT)
	{
		nbr = mandelbrot_iteration(nbr, constant);
		if (absolute_value(nbr) > 2)
			break;
	}
	return (i);
}

static void	print_grid(complx constant, double unit)
{
	int		i = 0;
	int		j = 0;
	double	rstart;

	rstart = constant.r;
	while (i++ < GRID_SIZE)
	{
		while (j++ < GRID_SIZE)
		{
			if (iterate_until_escape(constant) == ITERATION_LIMIT)
				ft_printf(".");
			else
				ft_printf(" ");
			constant.r += unit;
		}
		j = 0;
		constant.r = rstart;
		constant.i -= unit;
		ft_printf("\n");
	}
//	printf(" end = %.3f + %.3f | unit = %.2f\n", constant.r, constant.i, unit);
}

static void	display_fractal(void)
{
	complx	center;
	complx	start;
	double	unit;
	
	center.r = 0;
	center.i = 0;

	unit = (double) 3 / (double) GRID_SIZE;
	start = find_start(center, unit);
	print_grid(start, unit);
}

int	main(int argc, char *argv[])
{
	display_fractal();	
}
