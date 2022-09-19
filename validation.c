/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 12:56:46 by gcorreia          #+#    #+#             */
/*   Updated: 2022/09/19 14:12:23 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_error()
{
	ft_printf(RED"\n---Invalid argument---\n\n"RESET);
	ft_printf("The arguments should be as follows:\n\n");
	ft_printf(GREEN"./fractol "BLUE"<Name> "YLLW"<Iteration limit> "
			"<Window size> "PURPL "<Real part of the constant>"
		   	"<Imaginary part of the constant>\n\n"RESET);
	ft_printf("Examples:\n\n");
	ft_printf(GREEN"./fractol\t"BLUE"mandelbrot\t"YLLW"500  800\n");
	ft_printf(GREEN"./fractol\t"BLUE"mandelbrot\t"YLLW"1000 400\n");
	ft_printf(GREEN"./fractol\t"BLUE"julia\t\t"YLLW"700  600\t"PURPL
			" 0    1\n");
	ft_printf(GREEN"./fractol\t"BLUE"julia\t\t"YLLW"500  500\t"PURPL
			"-0.75 0\n");
	ft_printf(GREEN"./fractol\t"BLUE"julia\t\t"YLLW"400  800\t"PURPL
			"-1    0\n");
	ft_printf(GREEN"./fractol\t"BLUE"julia\t\t"YLLW"1000 1000\t"PURPL
			" 0.3  0.6\n");
	ft_printf(RESET"\n");
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
