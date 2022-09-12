#ifndef FRACT_OL
# define FRACT_OL

# include <math.h>
# include "libft/libft.h"
# include "mlx/mlx.h"

//# ifndef GRID_SIZE
//#  define GRID_SIZE 800
//# endif

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
	complx	start;
	complx	center;
	complx	constant;
	double	zoom;
	double	unit;
	char	*type;
	int		max_iterations;
	int		printed;
	int		*color;
	int		win_size;
}				t_render;

typedef struct	s_info
{
	t_vars		*vars;
	t_img		*img;
	t_render	*render;
}				t_info;


int		handle_mouse(int button, int x, int y, t_render *render);
int		handle_destroy(t_vars *vars);
int		handle_keypress(int keycode, t_vars *vars);
int		render_next_frame(t_info *info);
int		hsv_to_rgb(double h, double s, double v);
int		get_color(int iterations, int limit);
int		rgba(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
int		fractal_iteration(complx z, complx c, int limit);
int		*get_color_array(int limit);
void	check_arguments(int argc, char **argv);
void	pixel_put(t_img *img, int x, int y, int color);
void	initialize_image(t_info *info);
void	initialize_window(t_info *info);
void	initialize_fractal(int argc, char **argv, t_render *render);
void	draw_fractal(t_info *info);
void	print_mandelbrot(t_info *img);
void	print_julia(complx point, t_info *info);
double	absolute_value(complx nbr);
complx	find_start(complx center, double unit, int win_size);
complx	complx_pow(complx nbr, int power);
complx	complx_sum(complx a, complx b);


#endif
