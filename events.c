/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:16:33 by gcorreia          #+#    #+#             */
/*   Updated: 2022/09/08 15:27:56 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_keypress(int keycode, t_vars *vars)
{
//	ft_printf("keycode = %d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	handle_mouse(int button, int x, int y, t_render *render)
{
	if (button == 4)
		render->unit *= 0.8;
	else if (button == 5)
		render->unit *= 1.1;
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
