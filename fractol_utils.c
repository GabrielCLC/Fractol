#include "fractol.h"
#include <stdio.h>

complx	find_start(complx center, double unit)
{
	complx	start;

	start.r = center.r - unit * GRID_SIZE / 2;
	start.i = center.i + unit * GRID_SIZE / 2;
	return (start);
}

int	fractal_iteration(complx z, complx c, int limit)
{
	int		i;
	complx	temp;
	 
	temp = z;
	i = 0;
	while (i < limit)
	{ 
		if ((z.r * z.r) + (z.i * z.i) > 4)
			break;
		temp.r = (z.r * z.r - z.i * z.i) + c.r;
		temp.i = (2 * z.r * z.i) + c.i;
		z = temp;
		i++;
	}
	return (i);
}

void    print_julia(complx point, double unit, t_info *info)
{
	int     i;
	int     j;
	int		iterations;
	
	point = info->render->start;
	i = j = 0;
	while (i < GRID_SIZE)
	{
		while (j < GRID_SIZE)
		{
			iterations = fractal_iteration(point, info->render->constant, info->render->max_iterations);
			pixel_put(info->img, j, i, info->render->color[iterations]);
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
