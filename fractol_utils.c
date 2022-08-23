#include "fractol.h"

complx	find_start(complx center, double unit)
{
	complx	start;

	start.r = center.r - unit * GRID_SIZE / 2;
	start.i = center.i + unit * GRID_SIZE / 2;
	return (start);
}

int fractal_iteration(complx nbr, complx constant)
{
	int     i;
	                                                                                                               
	i = 0;
	while (i++ < ITERATION_LIMIT)
	{   
		nbr = complx_sum(complx_pow(nbr, 2), constant);
		if (absolute_value(nbr) > 2)
			break;
	}   
	return (i);
}

void    print_julia(complx point, complx constant, double unit)
{
	int     i;
	int     j;
	double  rstart;
	
	rstart = point.r;
	i = j = 0;
	while (i++ < GRID_SIZE)
	{
		while (j++ < GRID_SIZE)
		{
			if (fractal_iteration(point, constant) == ITERATION_LIMIT + 1)
				ft_printf(".");
			else
				ft_printf(" ");
			point.r += unit;
		}
		j = 0;
		point.r = rstart;
		point.i -= unit;
		ft_printf("\n");
	}
}

void    print_mandelbrot(complx constant, double unit)
{
	int     i;
	int     j;
	double  rstart;
	complx  zero;
	
	zero.r = zero.i = 0;
	rstart = constant.r;
	i = j = 0;
	while (i++ < GRID_SIZE)
	{
		while (j++ < GRID_SIZE)
		{
			if (fractal_iteration(zero, constant) == ITERATION_LIMIT + 1)
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
}

void	display_fractal(char *type)
{
	complx	center;
	complx	start;
	complx	constant;
	double	unit;

	center.r = center.i = 0;
	constant.r = -0.8;
	constant.i = 0.156;
	unit = (double) 3 / (double) GRID_SIZE;
	start = find_start(center, unit);
	if (!ft_strncmp(type, "mandelbrot", 10))
		print_mandelbrot(start, unit);
	else if (!ft_strncmp(type, "julia", 5))
		print_julia(start, constant, unit);
}
