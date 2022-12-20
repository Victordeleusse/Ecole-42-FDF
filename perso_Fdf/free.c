/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:23:06 by vde-leus          #+#    #+#             */
/*   Updated: 2022/12/20 18:52:56 by vde-leus         ###   ########.fr       */
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
	img->window = NULL;
	printf("window clean\n");
	if (img->mlx && img->image)
		mlx_destroy_image(img->mlx, img->image);
	img->image = NULL;
	printf("image clean\n");
	if (img->address)
		img->address = NULL;
	printf("adress clean\n");
	if (img->mlx)
		free(img->mlx);
	printf("mlx clean\n");
	if (img->p1)
		free(img->p1);
	if (img->p2)
		free(img->p2);
	free(img->tab_color);
	printf("tab clean\n");
}
