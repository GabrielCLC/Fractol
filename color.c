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
