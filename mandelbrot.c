#include "fractol.h"

int	mandelbrot_iteration(complx constant)
{
	int		i;
	complx	nbr;

	nbr.r = 0;
	nbr.i = 0;
	i = 0;
	while (i++ < ITERATION_LIMIT)
	{
		nbr = complx_sum(complx_pow(nbr, 2), constant);
		if (absolute_value(nbr) > 2)
			break;

	}
	return (i);
}

void	print_mandelbrot(complx constant, double unit)
{
	int		i;
	int		j;
	double	rstart;

	rstart = constant.r;
	i = 0;
	j = 0;
	while (i++ < GRID_SIZE)
	{
		while (j++ < GRID_SIZE)
		{
			if (mandelbrot_iteration(constant) == ITERATION_LIMIT + 1)
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
