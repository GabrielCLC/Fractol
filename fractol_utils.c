#include "fractol.h"

complx	find_start(complx center, double unit)
{
	complx	start;

	start.r = center.r - unit * GRID_SIZE / 2;
	start.i = center.i + unit * GRID_SIZE / 2;
	return (start);
}

int	fractal_iteration(complx nbr, complx constant, int limit)
{
	int	i;
	                                                                                                               
	i = 0;
	while (i++ < limit)
	{   
		nbr = complx_sum(complx_pow(nbr, 2), constant);
		if (absolute_value(nbr) > 2)
			break;
	}
// 	i = (i == ITERATION_LIMIT + 1) ? i : i + 1 - log10(sqrt(absolute_value(nbr)));
	return (i);
}

void    print_julia(complx point, double unit, t_info *info)
{
	int     i;
	int     j;
	int		iterations;
	int		color;
	
	point = info->render->start;
	i = j = 0;
	while (i < GRID_SIZE / 2)
	{
		while (j < GRID_SIZE)
		{
			iterations = fractal_iteration(point, info->render->constant, info->render->max_iterations);
			color = get_color(iterations, info->render->max_iterations);
			pixel_put(info->img, j, i, color);
			pixel_put(info->img, GRID_SIZE - j - 1, GRID_SIZE - i - 1, color);
			point.r += unit;
			j++;
		}
		j = 0;
		point.r = info->render->start.r;
		point.i -= unit;
		i++;
	}
}

void    print_mandelbrot(double unit, t_info *info)
{
	int     i;
	int     j;
	int		color;
	int		iterations;
	complx  zero;
	
	zero.r = zero.i = 0;
	info->render->constant = info->render->start;
	i = j = 0;
	while (i < GRID_SIZE)
	{
		while (j < GRID_SIZE)
		{
			iterations = fractal_iteration(zero, info->render->constant, info->render->max_iterations);
			color = get_color(iterations, info->render->max_iterations);
			pixel_put(info->img, j, i, color);
//			pixel_put(info->img, j, GRID_SIZE - 1 - i, color);
			info->render->constant.r += unit;
			j++;
		}
		j = 0;
		info->render->constant.r = info->render->start.r;
		info->render->constant.i -= unit;
		i++;
	}
}

void	draw_fractal(t_info *info)
{
	double	unit;

	unit = 3 / (GRID_SIZE * info->render->zoom);
	info->render->start = find_start(info->render->center, unit);
	if (!ft_strncmp(info->render->type, "mandelbrot", 10))
		print_mandelbrot(unit, info);
	else if (!ft_strncmp(info->render->type, "julia", 5))
		print_julia(info->render->start, unit, info);
}
