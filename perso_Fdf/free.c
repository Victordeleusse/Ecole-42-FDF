/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:23:06 by vde-leus          #+#    #+#             */
/*   Updated: 2022/12/22 12:06:02 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_vertex(t_data *img)
{
	size_t		i;
	size_t		j;

	j = 0;
	while (j < img->map->height)
	{
		i = 0;
		while (i < img->map->width)
		{
			free(img->vertex[j][i].indice_tab_color);
			i++;
		}
		free(img->vertex[j]);
		j++;
	}
	free(img->vertex);
}

void	ft_free_map(t_data *img)
{
	size_t		j;

	j = 0;
	while (j < img->map->height)
	{
		free(img->map->map_int[j]);
		j++;
	}
	free(img->map->map_int);
	free(img->map);
}

void	ft_free_data(t_data *img)
{
	if (img->mlx && img->window)
		mlx_destroy_window(img->mlx, img->window);
	if (img->mlx && img->image)
		mlx_destroy_image(img->mlx, img->image);
	if (img->mlx)
	{
		mlx_destroy_display(img->mlx);
		free(img->mlx);
	}
	if (img->p1)
		free(img->p1);
	if (img->p2)
		free(img->p2);
	if (img->tab_color)
		free(img->tab_color);
}

void	ft_group_free(t_data *img)
{
	ft_free_vertex(img);
	ft_free_map(img);
	ft_free_data(img);
	free(img);
	exit(0);
}
