#ifndef FRACT_OL
# define FRACT_OL

# include <math.h>
# include "libft/libft.h"
# include "mlx/mlx.h"

# ifndef GRID_SIZE
#  define GRID_SIZE 1000
# endif

# ifndef ITERATION_LIMIT
#  define ITERATION_LIMIT 100
# endif

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	complex_number
{
	double	r;
	double	i;	
}		complx;

int		rgba(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
int		fractal_iteration(complx nbr, complx constant);
void	pixel_put(t_data *data, int x, int y, int color);
void	draw_fractal(char *type, t_data *img);
void	print_mandelbrot(complx constant, double unit, t_data *img);
void	print_julia(complx point, complx constant, double unit, t_data *img);
double	absolute_value(complx nbr);
complx	find_start(complx center, double unit);
complx	complx_pow(complx nbr, int power);
complx	complx_sum(complx a, complx b);


#endif
