/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:00:57 by gcorreia          #+#    #+#             */
/*   Updated: 2022/08/29 16:12:35 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initialize_window(t_vars *vars, t_data *img)
{
	vars->mlx = mlx_init();
	img->img = mlx_new_image(vars->mlx, GRID_SIZE, GRID_SIZE);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	vars->win = mlx_new_window(vars->mlx, GRID_SIZE, GRID_SIZE, "Fract\'ol");
	mlx_hook(vars->win, 2, 1L<<0, handle_keypress, vars);
	mlx_hook(vars->win, 17, 0L, handle_destroy, vars);
	mlx_hook(vars->win, 4, 1L<<2, handle_mouse, vars);
}
