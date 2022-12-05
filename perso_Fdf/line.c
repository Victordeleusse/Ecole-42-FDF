/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:48:00 by vde-leus          #+#    #+#             */
/*   Updated: 2022/12/05 15:12:47 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_line(t_data *img, float x_s, float y_s, float x_f, float y_f, int color)
{
	float		delta_x;
	float		delta_y;
	int			hypot;
	float		nb_pixels;
	float		d1;

	delta_x = (float)(x_f - x_s);
	delta_y = (float)(y_f - y_s);
	hypot = (int)(delta_x * delta_x + delta_y * delta_y);
	nb_pixels = (float)ft_sqrt(hypot);
	delta_x = delta_x / (float)nb_pixels;
	delta_y = delta_y / nb_pixels;
	while (nb_pixels)
	{
		ft_mlx_put_pixel(img, (int)x_s, (int)y_s, color);
		x_s = x_s + delta_x;
		y_s = y_s + delta_y;
		nb_pixels = nb_pixels -1;
	}
}
