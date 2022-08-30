#ifndef FRACT_OL
# define FRACT_OL

# include <math.h>
# include "libft/libft.h"
# include "mlx/mlx.h"

# ifndef GRID_SIZE
#  define GRID_SIZE 1000
# endif

# ifndef ITERATION_LIMIT
#  define ITERATION_LIMIT 700
# endif

typedef struct	complex_number
{
	double	r;
	double	i;	
}		complx;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_render
{
	complx	center;
	complx	constant;
	double	zoom;
	int		max_iterations;
	char	*type;
	int		printed;
}				t_render;

typedef struct	s_info
{
	t_vars		*vars;
	t_img		*img;
	t_render	*render;
}				t_info;


int		handle_mouse(int button, int x, int y, t_vars *vars);
int		handle_destroy(t_vars *vars);
int		handle_keypress(int keycode, t_vars *vars);
int		hsv_to_rgb(double h, double s, double v);
int		get_color(int iterations);
int		rgba(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
int		fractal_iteration(complx nbr, complx constant);
void	pixel_put(t_img *data, int x, int y, int color);
void	initialize_window(t_vars *vars, t_img *img);
void	draw_fractal(t_info *info);
void	print_mandelbrot(complx constant, double unit, t_img *img);
void	print_julia(complx point, complx constant, double unit, t_img *img);
double	absolute_value(complx nbr);
double	modulus(double nbr);
complx	find_start(complx center, double unit);
complx	complx_pow(complx nbr, int power);
complx	complx_sum(complx a, complx b);


#endif
