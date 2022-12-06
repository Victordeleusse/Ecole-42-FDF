/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:04:41 by vde-leus          #+#    #+#             */
/*   Updated: 2022/12/06 18:37:55 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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

int	ft_new_color(int color_diff)
{
	t_color_rgb	rgb;
	int			new_color;

	new_color = 0;
	rgb = ft_get_rgb(COLOR_MIN);
	while (color_diff > 256)
	{
		if (color_diff > 256 * 256)
		{
			rgb.r++;
			color_diff = color_diff - 256 * 256;
		}
		if (color_diff > 256 * 256)
		{
			rgb.r++;
			color_diff = color_diff - 256 * 256;
		}
		if (color_diff > 256)
		{
			rgb.g++;
			color_diff = color_diff - 256;
		}
	}
	new_color = rgb.b + rgb.g * 256 + rgb.r * 256 * 256;
	return (new_color);
}

int	ft_color_pixel(t_map *map, int i, int j)
{
	int	min;
	int	max;
	int	color_panel;
	int	color_diff;
	int color_pixel;

	max = ft_max_map(map);
	min	= ft_min_map(map);
	color_panel = (COLOR_MAX - COLOR_MIN) / (max - min);
	color_diff = COLOR_MIN + (map->map_int[j][i] - min) * color_panel;
	color_pixel = ft_new_color(color_diff);
	return (color_pixel);
}
