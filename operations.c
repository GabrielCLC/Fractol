#include "fractol.h"

double	absolute_value(complx nbr)
{
	return (sqrt(pow(nbr.r, 2) + pow(nbr.i, 2)));
}

complx	complx_pow(complx nbr, int power)
{
	complx	result;

	result.r = pow(nbr.r, power) - pow(nbr.i, power);
	result.i = 2 * nbr.r * nbr.i;
	return (result);
}

complx	complx_sum(complx a, complx b)
{
	complx	result;

	result.r = a.r + b.r;
	result.i = b.r + b.i;
	return (result);
}

complx mandelbrot_iteration(complx nbr, complx constant)
{
	return (complx_sum(complx_pow(nbr, 2), constant));
}
