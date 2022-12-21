/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:06:26 by vde-leus          #+#    #+#             */
/*   Updated: 2022/12/21 10:32:16 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_cond_draw(t_data *img, int i, int j, float z)
{
	if ((int)img->vertex[j][i].z == (int)z)
	{
		ft_draw_line(img, img->vertex[j][i], \
			img->vertex[j][i + 1], img->tab_color);
		ft_draw_line(img, img->vertex[j][i], \
			img->vertex[j + 1][i], img->tab_color);
	}
}

void	ft_draw(t_data *img)
{
	int		i;
	int		j;
	float	z;
	float	z_max;

	z = (float)ft_min_map(img->map) * img->zoom / 12;
	z_max = (float)ft_max_map(img->map) * img->zoom / 12;
	ft_finish_proper(img, img->tab_color);
	while (z <= z_max)
	{
		j = 0;
		while (j < img->map->height -2)
		{
			i = 0;
			while (i < img->map->width - 1)
			{
				ft_cond_draw(img, i, j, z);
				i++;
			}
			j++;
		}
		z++;
	}
	ft_mlx_pack(img);
}

void	ft_cond_draw_heb(t_data *img, int i, int j, float z)
{
	if ((int)img->vertex[j][i + 1].z == (int)z)
	{	
		ft_draw_line(img, img->vertex[j][i + 1], \
			img->vertex[j][i], img->tab_color);
		ft_draw_line(img, img->vertex[j + 1][i], \
			img->vertex[j][i], img->tab_color);
	}
}

void	ft_draw_heb(t_data *img)
{
	int		i;
	int		j;
	float	z;
	float	z_max;

	z = (float)ft_min_map(img->map) * img->zoom / 12;
	z_max = (float)ft_max_map(img->map) * img->zoom / 12;
	ft_finish_proper(img, img->tab_color);
	while (z <= z_max)
	{
		j = img->map->height - 3;
		while (j >= 0)
		{
			i = img->map->width - 2;
			while (i >= 0)
			{
				ft_cond_draw_heb(img, i, j, z);
				i--;
			}
			j--;
		}
		z++;
	}
	ft_mlx_pack(img);
}

void	ft_finish_proper(t_data *img, int *tab_color)
{
	int	i;
	int	j;

	i = img->map->width - 1;
	j = 0;
	while (j < img->map->height - 2)
	{
		ft_draw_line(img, img->vertex[j][i], img->vertex[j + 1][i], tab_color);
		j++;
	}
	i = 0;
	while (i < img->map->width - 1)
	{
		ft_draw_line(img, img->vertex[j][i], img->vertex[j][i + 1], tab_color);
		i++;
	}
}
