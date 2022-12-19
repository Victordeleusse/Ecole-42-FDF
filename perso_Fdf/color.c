/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:16:07 by vde-leus          #+#    #+#             */
/*   Updated: 2022/12/19 10:11:34 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	RGB transformation : the idea is to be able to change color by adding more
// 	of blue, more of red or more of green to our color. 
//	
//	Colors came from 0 to 255 (FF equivalent in hexadecimal) -> fit in an int
//  as int is 4 bytes - also fit with unsigned char (each byte contains 
//  2^8 = 256 values) when a char comes from -128 to 127, an unsigned char 
//  comes from 0 to 255.
//
//	Getting the int/RGB conversion
//	

#include "fdf.h"

int	ft_get_red(int color)
{
	int	red;

	red = 0;
	while (color >= (256 * 256))
	{
		red++;
		color -= (256 * 256);
	}
	return (red);
}

int	ft_get_green(int color)
{
	int	green;

	green = 0;
	while (color >= (256 * 256))
		color -= (256 * 256);
	while (color >= 256)
	{
		green++;
		color -= 256;
	}
	return (green);
}

int	ft_get_blue(int color)
{
	int	blue;

	while (color >= (256 * 256))
		color -= (256 * 256);
	while (color >= 256)
		color -= 256;
	blue = color;
	return (blue);
}

t_color_rgb	ft_get_rgb(int color)
{
	t_color_rgb	rgb;

	rgb.b = ft_get_blue(color);
	rgb.g = ft_get_green(color);
	rgb.r = ft_get_red(color);
	return (rgb);
}

int	ft_get_int_color(t_color_rgb rgb)
{
	int	color;

	color = 0;
	color = color + rgb.b;
	color = color + 256 * rgb.g;
	color = color + 256 * 256 * rgb.r;
	return (color);
}

// int	main(void)
// {
// 	int			color_test;
// 	t_color_rgb	rgb;

// 	// color_test = 0xB0B6FF;
// 	// rgb = ft_get_rgb(color_test);
// 	// printf("Le b : %d\n", rgb.b);
// 	// printf("Le g : %d\n", rgb.g);
// 	// printf("Le r : %d\n", rgb.r);
// 	rgb.b = 255;
// 	rgb.g = 182;
// 	rgb.r = 176;
// 	color_test = ft_get_int_color(rgb);
// 	printf("La couleur en int : %d\n", color_test);
// 	return (0);
// }
