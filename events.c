/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:16:33 by gcorreia          #+#    #+#             */
/*   Updated: 2022/10/15 14:43:30 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static void	reset_render(t_render *render)
{
	render->center.r = 0;
	render->center.i = 0;
	render->unit = 3.0 / render->win_size;
	free(render->color);
	render->max_iterations = 200;
	render->color = get_color_array(render->max_iterations);

}

int	handle_keypress(int keycode, t_info *info)
{
	if (keycode == ESC)
	{
		free(info->render->color);
		mlx_destroy_window(info->vars->mlx, info->vars->win);
		exit(0);
	}
	else if (keycode == ONE)
	{
		ft_strlcpy(info->render->type, "julia", 6);
		info->render->constant.r = -0.54;
		info->render->constant.i = 0.54;
		reset_render(info->render);
	}
	else if (keycode == TWO)
	{
		ft_strlcpy(info->render->type, "julia", 6);
		info->render->constant.r = 0.34;
		info->render->constant.i = -0.05;
		reset_render(info->render);
	}
	else if (keycode == THREE)
	{
		ft_strlcpy(info->render->type, "julia", 6);
		info->render->constant.r = 0.37;
		info->render->constant.i = -0.1;
		reset_render(info->render);
	}
	else if (keycode == FOUR)
	{
		ft_strlcpy(info->render->type, "mandelbrot", 11);
		reset_render(info->render);
	}
	else if (keycode == PLUS)
	{
		free(info->render->color);
		if (info->render->max_iterations < 700)
			info->render->max_iterations += 20;
		info->render->color = get_color_array(info->render->max_iterations);
	}
	else if (keycode == MINUS)
	{
		free(info->render->color);
		if (info->render->max_iterations > 100)
			info->render->max_iterations -= 20;
		info->render->color = get_color_array(info->render->max_iterations);
	}
	info->render->printed = 0;
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
	if (button == SCRLDWN)
		render->unit *= 1.1;
	else if (button == SCRLUP)
		render->unit *= 0.9;
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
