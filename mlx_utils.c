/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:00:57 by gcorreia          #+#    #+#             */
/*   Updated: 2022/10/14 20:44:30 by gcorreia         ###   ########.fr       */
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
	info->img->img = mlx_new_image(info->vars->mlx, info->render->win_size,
			info->render->win_size);
	info->img->addr = mlx_get_data_addr(info->img->img,
			&info->img->bits_per_pixel, &info->img->line_length,
			&info->img->endian);
}

void	initialize_window(t_info *info)
{
	info->vars->mlx = mlx_init();
	info->vars->win = mlx_new_window(info->vars->mlx, info->render->win_size,
			info->render->win_size, "Fractal");
	mlx_hook(info->vars->win, 2, 1L << 0, handle_keypress, info);
	mlx_hook(info->vars->win, 17, 0L, handle_destroy, info);
	mlx_hook(info->vars->win, 4, 1L << 2, handle_mouse, info->render);
}

void	initialize_fractal(t_render *render)
{
	render->center.r = 0;
	render->center.i = 0;
	render->max_iterations = 200;
	render->win_size = 800;
	render->type = ft_strdup("julia");
	render->constant.r = -0.54;
	render->constant.i = 0.54;
	render->unit = 3.0 / render->win_size;
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
		mlx_destroy_image(info->vars->mlx, info->img->img);
	}
	return (0);
}
