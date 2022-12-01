/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:16:07 by vde-leus          #+#    #+#             */
/*   Updated: 2022/12/01 11:56:04 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*	
//	RGB transformation : the idea is to be able to change color by adding more
// 	of blue, more of red or more of green to our color. 
//	
//	Colors came from 0 to 255 (FF equivalent in hexadecimal) -> fit in an int as int 
//	is 4 bytes - also fit with unsigned char (each byte contains 2^8 = 256 values) when
//	a char comes from -128 to 127, an unsigned char comes from 0 to 255.
//	
*/

#include "fdf.h"

static char	*ft_putbase_hex(int color)
{
	char	*base;
	size_t	i;
	char	*color_hex;

	base = "0123456789ABCDEF";
	color_hex = (char *)malloc(sizeof(char) * 9);
	if (!color_hex)
		return (NULL);
	color_hex[8] = '\0';
	i = 7;
	while (i >= 2)
	{
		color_hex[i] = base[color % 16];
		color = color / 16;
		i--;
	}
	color_hex[0] = '0';
	color_hex[1] = 'x';
	return (color_hex);
}

static int	ft_get_blue(char *color_hex)
{
	size_t	i;
	size_t	j;
	int		blue;
	char	*base;

	base = "0123456789ABCDEF";
	i = 0;
	j = 0;
	while (base[i] != color_hex[7])
		i++;
	while (base[j] != color_hex[6])
		j++;
	printf(" %ld %ld \n", i , j);
	blue = j * 16 + i;
	return (blue);
}

static int	ft_get_green(char *color_hex)
{
	size_t	i;
	size_t	j;
	int		green;
	char	*base;

	base = "0123456789ABCDEF";
	i = 0;
	j = 0;
	while (base[i] != color_hex[5])
		i++;
	while (base[j] != color_hex[4])
		j++;
	printf(" %ld %ld \n", i , j);
	green = j * 16 + i;
	return (green);
}

static int	ft_get_red(char *color_hex)
{
	size_t	i;
	size_t	j;
	int		green;
	char	*base;

	base = "0123456789ABCDEF";
	i = 0;
	j = 0;
	while (base[i] != color_hex[5])
		i++;
	while (base[j] != color_hex[4])
		j++;
	printf(" %ld %ld \n", i , j);
	green = j * 16 + i;
	return (green);
}

int	ft_new_color(int color, int blue, int green, int red)
{
	t_color_rgb	color_rgb;
	int			new_color;
	char		*color_hex;

	color_hex = ft_putbase_hex(color);
	color_rgb.b = ft_get_blue(color_hex);
	color_rgb.g = ft_get_green(color_hex);
	color_rgb.r = ft_get_red(color_hex);
	free(color_hex);
	color_rgb.b = color_rgb.b + blue;
	color_rgb.g = color_rgb.g + green;
	color_rgb.r = color_rgb.r + red;
	new_color = color_rgb.b + color_rgb.g * 256 + color_rgb.r * 256 * 256;
	return (new_color);
}
