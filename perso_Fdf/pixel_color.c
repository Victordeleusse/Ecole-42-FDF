/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:04:41 by vde-leus          #+#    #+#             */
/*   Updated: 2022/12/12 11:03:47 by vde-leus         ###   ########.fr       */
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

int	*ft_generate_color_tab(void)
{
	int		*color_tab;
	int		color_change;
	int		i;

	i = 0;
	color_tab = ft_calloc((size_t) sizeof(int), (size_t) COLOR_TAB_SIZE);
	while (i < COLOR_TAB_SIZE)
	{
		color_tab[i] = COLOR_MIN + 256 * 2 * i + 256 * 256 * 2 * i;
		i++;
	}
	return (color_tab);
}

int	ft_color_vertex(t_map *map, int hauteur_z, \
	int *color_tab, int *indice_vertex)
{
	int	min;
	int	max;
	int	color_panel;
	int	color_diff;

	max = ft_max_map(map);
	min = ft_min_map(map);
	if (hauteur_z == max)
	{	
		*indice_vertex = COLOR_TAB_SIZE - 1;
		return (color_tab[COLOR_TAB_SIZE - 1]);
	}
	color_panel = COLOR_TAB_SIZE / (max - min);
	color_diff = (hauteur_z - min);
	*indice_vertex = color_diff * color_panel;
	return (color_tab[*indice_vertex]);
}
