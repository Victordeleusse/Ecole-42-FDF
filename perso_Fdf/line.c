/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:48:00 by vde-leus          #+#    #+#             */
/*   Updated: 2022/12/06 17:06:37 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_line(t_data *img, float x_s, float y_s, float x_f, float y_f, int color)
{
	float		delta_x;
	float		delta_y;
	int			hypot;
	float		nb_pixels;

	delta_x = (float)(x_f - x_s);
	delta_y = (float)(y_f - y_s);
	hypot = (int)(delta_x * delta_x + delta_y * delta_y);
	nb_pixels = (float)ft_sqrt(hypot);
	delta_x = delta_x / (float)nb_pixels;
	delta_y = delta_y / nb_pixels;
	while (nb_pixels)
	{
		ft_mlx_put_pixel(img, (int)x_s + 200, (int)y_s + 200, color);
		x_s = x_s + delta_x;
		y_s = y_s + delta_y;
		nb_pixels = nb_pixels - 1;
	}
}

void	ft_draw_line_vertex(t_data *img, t_vertex v1, t_vertex v2, int color)
{
	float		delta_x;
	float		delta_y;
	int			hypot;
	float		nb_pixels;

	delta_x = (float)(v2.x - v1.x);
	delta_y = (float)(v2.y - v1.y);
	hypot = (int)(delta_x * delta_x + delta_y * delta_y);
	nb_pixels = (float)ft_sqrt(hypot);
	delta_x = delta_x / (float)nb_pixels;
	delta_y = delta_y / nb_pixels;
	while (nb_pixels)
	{
		ft_mlx_put_pixel(img, (float)v1.x + 200, (float)v1.y + 200, color);
		v1.x = v1.x + delta_x;
		v1.y = v1.y + delta_y;
		nb_pixels = nb_pixels - 1;
	}
}
