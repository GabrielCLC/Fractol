/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:16:33 by gcorreia          #+#    #+#             */
/*   Updated: 2022/09/09 12:39:50 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	handle_keypress(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

static complx	find_center(complx previous, double unit, int x, int y)
{
	complx	center;
	complx	start;

	start = find_start(previous, unit);
	center.r = start.r + x * unit;
	center.i = start.i - y * unit;
	return (center);
}

int	handle_mouse(int button, int x, int y, t_render *render)
{
	if (button == 4)
		render->unit *= 1.2;
	else if (button == 5)
		render->unit *= 0.8;
	else if (button == 1)
		render->center = find_center(render->center, render->unit, x, y);
	render->printed = 0;
	return (0);
}

int	handle_destroy(t_vars *vars)
{
	ft_printf("clicked on 'x'\n");
	(void) vars;
	exit(0);
	return (0);
}
