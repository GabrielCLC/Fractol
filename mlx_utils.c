/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:00:57 by gcorreia          #+#    #+#             */
/*   Updated: 2022/09/09 12:46:34 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	initialize_image(t_info *info)
{
	info->img->img = mlx_new_image(info->vars->mlx, GRID_SIZE, GRID_SIZE);
	info->img->addr = mlx_get_data_addr(info->img->img,
			&info->img->bits_per_pixel, &info->img->line_length,
			&info->img->endian);
}

void	initialize_window(t_info *info)
{
	info->vars->mlx = mlx_init();
	info->vars->win = mlx_new_window(info->vars->mlx, GRID_SIZE, GRID_SIZE,
			"Fract\'ol");
	mlx_hook(info->vars->win, 2, 1L << 0, handle_keypress, info->vars);
	mlx_hook(info->vars->win, 17, 0L, handle_destroy, info->vars);
	mlx_hook(info->vars->win, 4, 1L << 2, handle_mouse, info->render);
}

void	initialize_fractal(int argc, char **argv, t_render *render)
{
	if (argc < 2)
	{
		ft_printf("Invalid argument");
		exit(0);
	}
	render->center.r = 0;
	render->center.i = 0;
	render->type = argv[1];
	render->constant.r = -0.8;
	render->constant.i = 0.156;
	render->unit = 3.0 / GRID_SIZE;
	render->max_iterations = 500;
	render->printed = 0;
	render->color = get_color_array(render->max_iterations);
}

int	render_next_frame(t_info *info)
{
	t_img	img;

	if (info->render->printed == 0)
	{
		info->img = &img;
		initialize_image(info);
		draw_fractal(info);
		mlx_put_image_to_window(info->vars->mlx, info->vars->win,
			info->img->img, 0, 0);
		info->render->printed = 1;
	}
	return (0);
}
