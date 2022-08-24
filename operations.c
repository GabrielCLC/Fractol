#include "fractol.h"
#include <stdio.h>

double	absolute_value(complx nbr)
{
	return (sqrt(pow(nbr.r, 2) + pow(nbr.i, 2)));
}

double	modulus(double nbr)
{
	if (nbr < 0)
		return (nbr * (-1));
	else return (nbr);
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
	result.i = a.i + b.i;
	return (result);
}
