/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:20:19 by vde-leus          #+#    #+#             */
/*   Updated: 2022/12/19 13:39:29 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <math.h>

t_vertex	*ft_generate_vertex(t_map *map, size_t j, int *color_tab)
{
	t_vertex	*v;
	size_t		i;

	i = 0;
	v = ft_calloc((size_t) sizeof(t_vertex), map->width);
	if (!v)
		return (NULL);
	while (i < map->width)
	{
		v[i].x = i;
		v[i].y = j;
		v[i].z = map->map_int[j][i];
		v[i].indice_tab_color = ft_calloc((size_t) sizeof(int), (size_t) 1);
		v[i].color = ft_color_vertex(map, map->map_int[j][i], \
			color_tab, v[i].indice_tab_color);
		i++;
	}
	return (v);
}

t_vertex	**ft_generate_vertex_map(t_map *map)
{
	int			*color_tab;
	t_vertex	**vtx;
	size_t		i;
	size_t		j;

	color_tab = ft_generate_color_tab();
	vtx = ft_calloc((size_t) sizeof(t_vertex *), map->height);
	if (!vtx)
		return (NULL);
	j = 0;
	while (j < map->height)
	{
		vtx[j] = ft_generate_vertex(map, j, color_tab);
		if (!vtx[j])
		{
			while (j > 0)
				free(vtx[--j]);
			free(vtx);
			return (NULL);
		}
		j++;
	}
	return (vtx);
}

void	ft_zoom(t_data *img)
{
	size_t		i;
	size_t		j;

	j = 0;
	while (j < img->map->height)
	{
		i = 0;
		while (i < img->map->width)
		{
			if (img->zoom <= 3)
				img->zoom = 3;
			img->vertex[j][i].x = img->vertex[j][i].x * img->zoom;
			img->vertex[j][i].y = img->vertex[j][i].y * img->zoom;
			if (img->zoom > 20)
				img->vertex[j][i].z = img->vertex[j][i].z * (img->zoom / 18);
			else
				img->vertex[j][i].z = img->vertex[j][i].z * (img->zoom / 12);
			i++;
		}
		j++;
	}
}

void	ft_centrage_vertex_map(t_vertex **vertex_map, t_map *map)
{
	size_t	i;
	size_t	j;
	float	x_max;
	float	y_max;

	x_max = vertex_map[0][map->width - 1].x;
	y_max = vertex_map[map->height - 1][0].y;
	j = 0;
	while (j < map->height)
	{
		i = 0;
		while (i < map->width)
		{
			vertex_map[j][i].x = vertex_map[j][i].x - x_max / 2;
			vertex_map[j][i].y = vertex_map[j][i].y - y_max / 2;
			i++;
		}
		j++;
	}
}

void	ft_rotation_plane(t_data *img)
{
	size_t		i;
	size_t		j;
	float		k;

	j = 0;
	while (j < img->map->height)
	{
		i = 0;
		k = 0;
		while (i < img->map->width)
		{	
			k = img->vertex[j][i].x;
			img->vertex[j][i].x = img->vertex[j][i].x * cos(img->angle_rotation_plan / 57.2958) - img->vertex[j][i].y * sin(img->angle_rotation_plan / 57.2958);
			img->vertex[j][i].y = k * sin(img->angle_rotation_plan / 57.2958) + img->vertex[j][i].y * cos(img->angle_rotation_plan / 57.2958);
			i++;
		}
		j++;
	}
}

void	ft_rotation_axe_y(t_data *img)
{
	size_t		i;
	size_t		j;
	float		k;

	j = 0;
	while (j < img->map->height)
	{
		i = 0;
		k = 0;
		while (i < img->map->width)
		{	
			k = img->vertex[j][i].x;
			img->vertex[j][i].x = img->vertex[j][i].z * -cos(img->angle_rotation_y / 57.2958) + img->vertex[j][i].x * sin(img->angle_rotation_y / 57.2958);
			i++;
		}
		j++;
	}
}
