/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 12:56:46 by gcorreia          #+#    #+#             */
/*   Updated: 2022/09/13 18:39:10 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_error()
{
	ft_printf(RED"\n---Invalid argument---\n\n"RESET);
	ft_printf("the arguments should be as follows:\n\n");
	ft_printf("./fractol "BLUE"<Name> "YLLW"<Iteration limit> "
			GREEN"<Window size> ");
	ft_printf("<Real part of the constant> <Imaginary part of the constant>\n\n");
	ft_printf("examples:\n");
	ft_printf("./fractol mandelbrot 500 800\n");
	ft_printf("./fractol mandelbrot 1000 400\n");
	ft_printf("./fractol julia 700 600 0 1\n");
	ft_printf("./fractol julia 500 500 -0.75 0\n");
	ft_printf("./fractol julia 400 800 -1 0\n");
	ft_printf("./fractol julia 1000 800 0.3 0.6\n");
}

void	check_render_options(char	**argv)
{
	if (ft_atoi(argv[2]) <= 0 || ft_atoi(argv[3]) <= 0
		|| ft_atoi(argv[3]) > 1080)
	{
		print_error();
		exit (0);
	}
}

void	check_argc(char *type, int argc)
{
	if (!ft_strncmp(type, "julia", 6) && argc < 6)
	{
		print_error();
		exit (0);
	}
	else if (!ft_strncmp(type, "mandelbrot", 11) && argc < 4)
	{
		print_error();
		exit (0);
	}
}

void	check_type(char	*type)
{
	if (!type || (ft_strncmp(type, "julia", 6)
			&& ft_strncmp(type, "mandelbrot", 11)))
	{
		print_error();
		exit (0);
	}
}

void	check_arguments(int argc, char **argv)
{
	check_type(argv[1]);
	check_argc(argv[1], argc);
	check_render_options(argv);
}
