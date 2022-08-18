#ifndef FRACT_OL
# define FRACT_OL

# include <math.h>
# include "libft/libft.h"

# ifndef GRID_SIZE
#  define GRID_SIZE 40
# endif

typedef struct	complex_number
{
	double	r;
	double	i;	
}		complx;

double	absolute_value(complx nbr);
complx	complx_pow(complx nbr, int power);
complx	complx_sum(complx a, complx b);
complx	mandelbrot_iteration(complx nbr, complx constant);


#endif
