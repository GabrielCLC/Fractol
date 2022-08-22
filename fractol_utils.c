#include "fractol.h"

complx	find_start(complx center, double unit)
{
	complx	start;

	start.r = center.r - unit * GRID_SIZE / 2;
	start.i = center.i + unit * GRID_SIZE / 2;
	return (start);
}

