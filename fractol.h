#ifndef FRACT_OL
# define FRACT_OL

# include <math.h>
# include "libft/libft.h"

# ifndef GRID_SIZE
#  define GRID_SIZE 80
# endif

# ifndef ITERATION_LIMIT
#  define ITERATION_LIMIT 100
# endif


typedef struct	complex_number
{
	double	r;
	double	i;	
}		complx;

int		fractal_iteration(complx nbr, complx constant);
void	print_mandelbrot(complx constant, double unit);
void	print_julia(complx point, complx constant, double unit);
double	absolute_value(complx nbr);
complx	find_start(complx center, double unit);
complx	complx_pow(complx nbr, int power);
complx	complx_sum(complx a, complx b);


#endif
