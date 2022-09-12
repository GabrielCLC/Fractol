/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 12:34:04 by gcorreia          #+#    #+#             */
/*   Updated: 2022/09/12 12:14:58 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	modulus(double nbr)
{
	if (nbr < 0)
		nbr *= -1;
	return (nbr);
}

int	hsv_to_rgb(double h, double s, double v)
{
	double	m;
	double	n;
	double	z;
	int		rgb;

	rgb = 0;
	m = 255 - s;
	n = 255.0 * (v / 255.0);
	z = (v - m) * (1.0 - modulus(((h / 60) / 2.0 - (int)(h / 60) / 2) - 1.0));
	if (h >= 0 && h < 60)
		rgb = (int)n << 16 | (int)(z + m) << 8 | (int) m;
	else if (h >= 60 && h < 120)
		rgb = (int)(z + m) << 16 | (int)n << 8 | (int)m;
	else if (h >= 120 && h < 180)
		rgb = (int)m << 16 | (int)n << 8 | (int)(z + m);
	else if (h >= 180 && h < 240)
		rgb = (int)m << 16 | (int)(z + m) << 8 | (int)n;
	else if (h >= 240 && h < 300)
		rgb = (int)(z + m) << 16 | (int)m << 8 | (int)n;
	else
		rgb = (int)n << 16 | (int)m << 8 | (int)(z + m);
	return (rgb);
}

int	get_color(int iterations, int limit)
{
	double	h;
	double	s;
	double	v;
	int		color;

	s = 100 + 155 * iterations / limit;
	h = 360 * (double) iterations / limit;
	v = 100 + 100 * iterations / limit;
	if (iterations == limit)
		return (0);
	color = hsv_to_rgb(h, s, v);
	return (color);
}

int	*get_color_array(int limit)
{
	int	*array;
	int	i;

	array = malloc(sizeof(int) * (limit + 1));
	if (!array)
	{
		ft_printf("failed to allocate color array\n");
		exit(0);
	}
	i = 0;
	while (i <= limit)
	{
		array[i] = get_color(i, limit);
		i++;
	}
	return (array);
}
