/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 12:30:54 by gcorreia          #+#    #+#             */
/*   Updated: 2022/09/09 12:30:58 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char *argv[])
{
	t_vars		vars;
	t_render	render;
	t_info		info;

	info.vars = &vars;
	info.render = &render;
	initialize_fractal(argc, argv, info.render);
	initialize_window(&info);
	mlx_loop_hook(vars.mlx, render_next_frame, &info);
	mlx_loop(vars.mlx);
}
