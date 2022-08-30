#include "fractol.h"

void	pixel_put(t_img *data, int x, int y, int color)
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

	rgb = 0;
	m = 255 - s;
	M = 255.0 * (v / 255.0);
	z = (v - m) * (1.0 - modulus(((h / 60) / 2.0 - (int) (h / 60) / 2) - 1.0));
	if (h >= 0 && h < 60)
		rgb = (int) (z + m) << 16 | (int) m << 8 | (int) M;
	else if (h >= 60 && h < 120)
		rgb = (int) m << 16 | (int) (z + m) << 8 | (int) M;
	else if (h >= 120 && h < 180)
		rgb = (int) m << 16 | (int) M << 8 | (int) (z + m);
	else if (h >= 180 && h < 240)
		rgb = (int) (z + m)  << 16 | (int) M << 8 | (int) m;
	else if (h >= 240 && h < 300)
		rgb = (int) M << 16 | (int) (z + m) << 8 | (int) m;
	else
		rgb = (int) M << 16 | (int) m << 8 | (int) (z + m);
	return (rgb);

}

int	get_color(int iterations, int limit)
{
	double	h;
	double	s;
	double	v;
	int		color;

	s = 255;
	h = 360.0 * (double) iterations / limit;
	if (iterations == limit + 1)
		return (0);
	if (iterations <= 210)
		v = (50 + 10 * (iterations / 10)) + 10 * iterations / (10 * (iterations / 10 + 1));
	else
		v = 255; 
	color = hsv_to_rgb(h, s, v);
	return (color);
}
