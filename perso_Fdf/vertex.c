/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:20:19 by vde-leus          #+#    #+#             */
/*   Updated: 2022/12/06 16:52:41 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <math.h>

t_vertex	*ft_generate_vertex(t_map *map, size_t j)
{
	t_vertex	*v;
	size_t		i;

	i = 0;
	v = ft_calloc((size_t) sizeof(t_vertex), map->width);
	if (!v)
		return (NULL);
	while (i < map->width)
	{
		v[i].x = i * ZOOM;
		v[i].y = j * ZOOM;
		v[i].z = map->map_int[j][i];
		v[i].color = ft_color_pixel(map, i, j);
		i++;
	}
	return (v);
}

t_vertex	**ft_generate_vertex_map(t_map *map)
{
	t_vertex	**vtx;
	size_t		i;
	size_t		j;

	vtx = ft_calloc((size_t) sizeof(t_vertex *), map->height);
	if (!vtx)
		return (NULL);
	j = 0;
	while (j < map->height)
	{
		vtx[j] = ft_generate_vertex(map, j);
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

void	ft_rotation(t_data *img)
{
	size_t		i;
	size_t		j;

	j = 0;
	while (j < img->map->height)
	{
		i = 0;
		while (i < img->map->width)
		{	
			img->vertex[j][i].x = 0.5 * (img->vertex[j][i].x - img->vertex[j][i].y);
			img->vertex[j][i].y = 0.25 * (img->vertex[j][i].x + img->vertex[j][i].y);
			// img->vertex[j][i].x = img->vertex[j][i].x +  cos(THETA) * img->vertex[j][i].z;
			// img->vertex[j][i].y = img->vertex[j][i].y - img->vertex[j][i].z * sin(THETA);
			i++;
		}
		j++;
	}
}
