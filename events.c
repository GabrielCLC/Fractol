/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:16:33 by gcorreia          #+#    #+#             */
/*   Updated: 2022/09/19 15:10:38 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	handle_keypress(int keycode, t_info *info)
{
	if (keycode == 53)
	{
		free(info->render->color);
		mlx_destroy_window(info->vars->mlx, info->vars->win);
		exit(0);
	}
	return (0);
}

static void	update_center(t_render *render, int x, int y)
{
	complx	start;

	start = find_start(render->center, render->unit, render->win_size);
	render->center.r = start.r + x * render->unit;
	render->center.i = start.i - y * render->unit;
}

int	handle_mouse(int button, int x, int y, t_render *render)
{
	if (button == 4)
		render->unit *= 1.2;
	else if (button == 5)
		render->unit *= 0.8;
	else if (button == 1)
		update_center(render, x, y);
	render->printed = 0;
	return (0);
}

int	handle_destroy(t_info *info)
{
	free(info->render->color);
	mlx_destroy_window(info->vars->mlx, info->vars->win);
	exit(0);
	return (0);
}
