#include <stdio.h>
#include "fractol.h"

static void	print_grid(char **grid)
{
	int	i;

	i = 0;
	while (i < GRID_SIZE)
	{
		ft_printf("%s\n", grid[i]);
		i++;
	}
}

static complx	find_first_constant(double center, double unit)
{
	complx	start;
	
	start.r = center - unit * GRID_SIZE/2;
	start.i = center + unit * GRID_SIZE/2;

	return (start);
}

int iterate_until_escape(complx constant, int max)
{
	int	i;
	complx	nbr;

	nbr.r = 0;
	nbr.i = 0;
	i = 0;
	while (i < max)
	{
		nbr = mandelbrot_iteration(nbr, constant);
		if (absolute_value(nbr) > 2)
			break;
		i++;
	}
	return (i);
}

static void	fill_grid(char **grid)
{
	double	unit;
	double	center = 0;
	double	rstart;
	int	i = 0;
	int	j = 0;
	int	limit = 2000;
	complx	constant;
	
	unit = (double)4/(double)GRID_SIZE;
	constant = find_first_constant(center, unit);
	rstart = constant.r;
	printf("start = %.3f + %.3f", constant.r, constant.i);
	while (i < GRID_SIZE)
	{
		constant.r = rstart;
		while (j < GRID_SIZE)
		{
			if (iterate_until_escape(constant, limit) == limit)
				grid[i][j] = '.';
			else
				grid[i][j] = ' ';
			constant.r += unit;
			j++;
		}
		j = 0;
		constant.i -= unit;
		i++;
	}
	printf(" end = %.3f + %.3f\n", constant.r, constant.i);
}

static void	display_fractal(void)
{
	char	**grid;

	grid = ft_calloc(GRID_SIZE, sizeof(char *));
	for (int i = 0; i < GRID_SIZE; i++)
		grid[i] = malloc(GRID_SIZE);
	fill_grid((char **)grid);
	print_grid((char **)grid);
}

int	main(int argc, char *argv[])
{
	display_fractal();	
}
