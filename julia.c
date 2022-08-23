#include "fractol.h"

int	julia_iteration(complx nbr, complx constant)
{
	int		i;

	i = 0;
	while (i++ < ITERATION_LIMIT)
	{
		nbr = complx_sum(complx_pow(nbr, 2), constant);
		if (absolute_value(nbr) > 22)
			break;
	}
	return (i);
}

void	print_julia(complx point, complx constant, double unit)
{
	int		i;
	int		j;
	double	rstart;

	rstart = point.r;
	i = j = 0;
	while (i++ < GRID_SIZE)
	{
		while (j++ < GRID_SIZE)
		{
			if (julia_iteration(point, constant) == ITERATION_LIMIT + 1)
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
