/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:04:41 by vde-leus          #+#    #+#             */
/*   Updated: 2022/12/04 11:24:58 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Rassembler min et max en void avec pointeurs sur int

#include "fdf.h"

int	ft_max_map(t_map *map)
{
	size_t	i;
	size_t	j;
	int		max;

	j = 0;
	max = 0;
	while (j < map->height)
	{
		i = 0;
		while (i < map->width)
		{
			if (map->map_int[j][i] > max)
				max = map->map_int[j][i];
			i++;
		}
		j++;
	}
	return (max);
}

int	ft_min_map(t_map *map)
{
	size_t	i;
	size_t	j;
	int		min;

	j = 0;
	min = 0;
	while (j < map->height)
	{
		i = 0;
		while (i < map->width)
		{
			if (map->map_int[j][i] < min)
				min = map->map_int[j][i];
			i++;
		}
		j++;
	}
	return (min);
}

int	ft_new_color(int color, int diff)
{
	t_color_rgb	rgb;
	int			new_color;

	rgb = ft_get_rgb(color);
	while (rgb.b <= 255 && diff)
	{
		rgb.b++;
		diff--;
	}
	while (rgb.g <= 255 && diff)
	{
		rgb.g++;
		diff--;
	}
	while (rgb.r <= 255 && diff)
	{
		rgb.r++;
		diff--;
	}
	new_color = rgb.b + rgb.g * 256 + rgb.r * 256 * 256;
	return (new_color);
}

int	ft_color_pixel(t_map *map, int i, int j)
{
	int	min;
	int	max;
	int	color_diff;
	int color_pixel;

	max = ft_max_map(map);
	min	= ft_min_map(map);
	color_diff = (COLOR_MAX - COLOR_MIN) / (max - min);
	color_pixel = COLOR_MIN + (map->map_int[j][i] - min) * color_diff;
	return (color_pixel);
}
