#include "fractol.h"

complx	find_start(complx center, double unit)
{
	complx	start;

	start.r = center.r - unit * GRID_SIZE / 2;
	start.i = center.i + unit * GRID_SIZE / 2;
	return (start);
}

int	fractal_iteration(complx nbr, complx constant)
{
	int	i;
	                                                                                                               
	i = 0;
	while (i++ < ITERATION_LIMIT)
	{   
		nbr = complx_sum(complx_pow(nbr, 2), constant);
		if (absolute_value(nbr) > 2)
			break;
	}
// 	i = (i == ITERATION_LIMIT + 1) ? i : i + 1 - log10(sqrt(absolute_value(nbr)));
	return (i);
}

void    print_julia(complx point, complx constant, double unit, t_data *img)
{
	int     i;
	int     j;
	int	iterations;
	int		color;
	double  rstart;

	rstart = point.r;
	i = j = 0;
	while (i < GRID_SIZE / 2)
	{
		while (j < GRID_SIZE)
		{
			iterations = fractal_iteration(point, constant);
			color = get_color(iterations);
			pixel_put(img, j, i, color);
			pixel_put(img, GRID_SIZE - j - 1, GRID_SIZE - i - 1, color);
			point.r += unit;
			j++;
		}
		j = 0;
		point.r = rstart;
		point.i -= unit;
		i++;
	}
}

void    print_mandelbrot(complx constant, double unit, t_data *img)
{
	int     i;
	int     j;
	double  rstart;
	int		color;
	int		iterations;
	complx  zero;
	
	zero.r = zero.i = 0;
	rstart = constant.r;
	i = j = 0;
	while (i < GRID_SIZE / 2)
	{
		while (j < GRID_SIZE)
		{
			iterations = fractal_iteration(zero, constant);
			color = get_color(iterations);
			pixel_put(img, j, i, color);
			pixel_put(img, j, GRID_SIZE - 1 - i, color);
			constant.r += unit;
			j++;
		}
		j = 0;
		constant.r = rstart;
		constant.i -= unit;
		i++;
	}
}

void	draw_fractal(char *type, t_data *img)
{
	complx	center;
	complx	start;
	complx	constant;
	double	unit;

	center.r = center.i = 0;
	constant.r = -0.7269;
	constant.i = 0.1889;
	unit = (double) 3 / (GRID_SIZE * 100000);
	start = find_start(center, unit);
	if (!ft_strncmp(type, "mandelbrot", 10))
		print_mandelbrot(start, unit, img);
	else if (!ft_strncmp(type, "julia", 5))
		print_julia(start, constant, unit, img);
}
