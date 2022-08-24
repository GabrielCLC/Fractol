#include "fractol.h"

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	rgba(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

int	hsv_to_rgb(double h, double s, double v)
{
	double	m;
	double	M;
	double	z;
	int		rgb;

	if (v == 0)
		return (0);
	rgb = 0;
	m = 255 - s;
	M = 255.0 * (255.0 / v);
	z = (v - m) * (1.0 - modulus(((h / 60) / 2.0 - (int) (h / 60) / 2) - 1.0));
	if (h >= 0 && h < 60)
		rgb = (int) M << 16 | (int) (z + m) << 8 | (int) m;
	else if (h >= 60 && h < 120)
		rgb = (int) (z + m)  << 16 | (int) M << 8 | (int) m;
	else if (h >= 120 && h < 180)
		rgb = (int) m << 16 | (int) M << 8 | (int) (z + m);
	else if (h >= 180 && h < 240)
		rgb = (int) m << 16 | (int) (z + m) << 8 | (int) M;
	else if (h >= 240 && h < 300)
		rgb = (int) (z + m) << 16 | (int) m << 8 | (int) M;
	else
		rgb = (int) M << 16 | (int) m << 8 | (int) (z + m);
	return (rgb);

}

int	get_color(int iterations)
{
	double	h;
	double	s;
	double	v;
	int		color;

	h = 360.0 * (double) iterations / (double) ITERATION_LIMIT;
	s = 255;
	if (iterations == ITERATION_LIMIT + 1)
		v = 0;
	else
		v = 255;
	color = hsv_to_rgb(h, s, v);
	return (color);
}
