/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:16:33 by gcorreia          #+#    #+#             */
/*   Updated: 2022/08/29 16:14:01 by gcorreia         ###   ########.fr       */
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

int	handle_mouse(int button, int x, int y, t_vars *vars)
{
	if (button == 4)
		ft_printf("zoomed out at (%d, %d)\n", x, y);
	else if (button == 5)
		ft_printf("zoomed in at (%d, %d)\n", x, y);
	(void) vars;
	return (0);
}

int	handle_destroy(t_vars *vars)
{
	ft_printf("clicked on 'x'\n");
	(void) vars;
	exit(0);
	return (0);
}
