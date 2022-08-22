#include "fractol.h"
#include <stdio.h>

double	absolute_value(complx nbr)
{
	return (sqrt(pow(nbr.r, 2) + pow(nbr.i, 2)));
}

complx	complx_pow(complx nbr, int power)
{
	complx	result;

//	printf("B4 pow = %.2f + %.2fi\n", nbr.r, nbr.i);
	result.r = pow(nbr.r, power) - pow(nbr.i, power);
	result.i = 2 * nbr.r * nbr.i;
//	printf("after pow = %.2f + %.2fi\n", result.r, result.i);
	return (result);
}

complx	complx_sum(complx a, complx b)
{
	complx	result;

	result.r = a.r + b.r;
	result.i = a.i + b.i;
	return (result);
}

complx mandelbrot_iteration(complx nbr, complx constant)
{
	complx	temp;

//	printf("B4 iteration = %.2f + %.2fi\n", nbr.r, nbr.i);
	temp = complx_sum(complx_pow(nbr, 2), constant);
//	printf("after iteration = %.2f + %.2fi\n", temp.r, temp.i);
	return (complx_sum(complx_pow(nbr, 2), constant));
}
