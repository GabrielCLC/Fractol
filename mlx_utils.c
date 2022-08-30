/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:00:57 by gcorreia          #+#    #+#             */
/*   Updated: 2022/08/30 15:37:12 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initialize_window(t_info *info)
{
	info->vars->mlx = mlx_init();
	info->img->img = mlx_new_image(info->vars->mlx, GRID_SIZE, GRID_SIZE);
	info->img->addr = mlx_get_data_addr(info->img->img, &info->img->bits_per_pixel,
		   						&info->img->line_length, &info->img->endian);
	info->vars->win = mlx_new_window(info->vars->mlx, GRID_SIZE, GRID_SIZE, "Fract\'ol");
	mlx_hook(info->vars->win, 2, 1L<<0, handle_keypress, info->vars);
	mlx_hook(info->vars->win, 17, 0L, handle_destroy, info->vars);
	mlx_hook(info->vars->win, 4, 1L<<2, handle_mouse, info->render);
}
