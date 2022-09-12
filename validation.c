/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 12:56:46 by gcorreia          #+#    #+#             */
/*   Updated: 2022/09/12 11:58:32 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_render_options(char	**argv)
{
	if (ft_atoi(argv[2]) <= 0 || ft_atoi(argv[3]) <= 0 || ft_atoi(argv[3]) > 1080)
	{
		ft_printf("Invalid argument\n");
		exit (0);
	}
}

void	check_argc(char *type, int argc)
{
	if (!ft_strncmp(type, "julia", 6) && argc < 6)
	{
		ft_printf("Invalid argument\n");
		exit (0);
	}
	else if (!ft_strncmp(type, "mandelbrot", 11) && argc < 4)
	{
		ft_printf("Invalid argument\n");
		exit (0);
	}
}

void	check_type(char	*type)
{
	if (!type || (ft_strncmp(type, "julia", 6) &&
			   ft_strncmp(type, "mandelbrot", 11)))
	{
		ft_printf("Invalid argument\n");
		exit (0);
	}
}

void	check_arguments(int argc, char **argv)
{
	check_type(argv[1]);
	check_argc(argv[1], argc);
	check_render_options(argv);
}
