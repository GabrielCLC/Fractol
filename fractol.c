#include <stdio.h>
#include "fractol.h"

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		ft_printf("Invalid argument\n");
		return (0);
	}
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	img.img = mlx_new_image(mlx, GRID_SIZE, GRID_SIZE);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mlx_win = mlx_new_window(mlx, GRID_SIZE, GRID_SIZE, "Hello World");
	draw_fractal(argv[1], &img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

	mlx_loop(mlx);

}
