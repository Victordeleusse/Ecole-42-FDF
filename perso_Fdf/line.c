/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:48:00 by vde-leus          #+#    #+#             */
/*   Updated: 2022/12/21 10:24:11 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_color_indice_pixel(t_vertex v1, t_vertex v2, float nb_pixels)
{
	int	delta_indice;
	int	count;

	if (!nb_pixels)
		return (0);
	if (v1.z == v2.z)
		return (0);
	delta_indice = *(v2.indice_tab_color) - *(v1.indice_tab_color);
	count = (int)roundf((float)delta_indice / nb_pixels);
	if (count == 0 && ((float)delta_indice / nb_pixels) < 0)
		return (-1);
	if (count == 0 && ((float)delta_indice / nb_pixels) > 0)
		return (1);
	return (count);
}

int	ft_get_color(int *temp, t_vertex v1, t_vertex v2, float nb_pixels)
{
	int	max;
	int	min;

	*(temp) = *(temp) + ft_color_indice_pixel(v1, v2, nb_pixels);
	if (*(temp) > 99)
		*(temp) = 99;
	if (*(temp) < 0)
		*(temp) = 0;
	if (*v1.indice_tab_color < *v2.indice_tab_color)
	{	
		max = *v2.indice_tab_color;
		min = *v1.indice_tab_color;
	}
	else
	{
		max = *v1.indice_tab_color;
		min = *v2.indice_tab_color;
	}
	if (*(temp) >= max)
		*(temp) = max;
	if (*(temp) <= min)
		*(temp) = min;
	return (*(temp));
}

void	ft_draw_line(t_data *img, t_vertex v1, t_vertex v2, int *color_tab)
{
	float		delta_x;
	float		delta_y;
	float		nb_pixels;
	int			*temp;

	delta_x = (float)(v2.x - v1.x);
	delta_y = (float)(v2.y - v1.y);
	nb_pixels = (float)ft_sqrt((int)(delta_x * delta_x + delta_y * delta_y));
	if (nb_pixels < 1)
		nb_pixels = 1;
	delta_x = delta_x / nb_pixels;
	delta_y = delta_y / nb_pixels;
	temp = (int *)malloc(sizeof(int));
	*temp = *v1.indice_tab_color;
	while (nb_pixels--)
	{
		*(temp) = ft_get_color(temp, v1, v2, nb_pixels);
		if ((float)v1.x + 800 > 0 && (float)v1.y + 750 > 0)
			ft_mlx_put_pixel(img, (float)v1.x + 800, (float)v1.y + 750 \
			, color_tab[*(temp)]);
		v1.x = v1.x + delta_x;
		v1.y = v1.y + delta_y;
	}
	free(temp);
}

float	*ft_generate_doublette(float x, float y)
{
	float	*p;

	p = (float *)malloc(sizeof(float) * 2);
	if (!p)
		return (NULL);
	p[0] = x;
	p[1] = y;
	return (p);
}

void	ft_draw_red_line(t_data *img)
{
	float		delta_x;
	float		delta_y;
	int			hypot;
	int			hypotata;
	double		nb_pixels;

	delta_x = (float)(img->p2[0] - img->p1[0]);
	delta_y = (float)(img->p2[1] - img->p1[1]);
	hypot = (delta_x * delta_x + delta_y * delta_y);
	nb_pixels = (float)ft_sqrt(hypot);
	if (nb_pixels < 1)
		nb_pixels = 1;
	delta_x = delta_x / nb_pixels;
	delta_y = delta_y / nb_pixels;
	while (nb_pixels--)
	{
		hypot = round(img->p1[0]);
		hypotata = round(img->p1[1]);
		ft_mlx_put_pixel(img, hypot, hypotata, 0xFF0000);
		img->p1[0] = img->p1[0] + delta_x;
		img->p1[1] = img->p1[1] + delta_y;
	}
}
