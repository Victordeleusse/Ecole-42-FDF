/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:48:00 by vde-leus          #+#    #+#             */
/*   Updated: 2022/12/09 16:38:15 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_color_indice_pixel(t_vertex v1, t_vertex v2, float nb_pixels)
{
	int	delta_indice;
	int	count;
	size_t	i;

	if (!nb_pixels)
		return (0);
	if (v1.z == v2.z)
		return (0);
	delta_indice = *(v2.indice_tab_color) - *(v1.indice_tab_color);
	count = (int)roundf((float)delta_indice / nb_pixels);
	return (count);
}

void	ft_draw_line(t_data *img, t_vertex v1, t_vertex v2, int *color_tab)
{
	float		delta_x;
	float		delta_y;
	int			hypot;
	float		nb_pixels;
	int			color_indice;
	int			*temp_indice_color;

	delta_x = (float)(v2.x - v1.x);
	delta_y = (float)(v2.y - v1.y);
	hypot = (int)(delta_x * delta_x + delta_y * delta_y);
	nb_pixels = (float)ft_sqrt(hypot);
	delta_x = delta_x / (float)nb_pixels;
	delta_y = delta_y / nb_pixels;
	printf("position1 : x-> %f, y-> %f, z-> %f || ", v1.x, v1.y, v1.z);
	// printf("position2 : x-> %f, y-> %f, z-> %f \n ", v2.x, v2.y, v2.z);
	// printf("delta indice : %d\n", *(v2.indice_tab_color) - *(v1.indice_tab_color));
	color_indice = ft_color_indice_pixel(v1, v2, nb_pixels);
	// printf("color indice : %d\n", color_indice);
	temp_indice_color = (int *)malloc(sizeof(int));
	*temp_indice_color = *v1.indice_tab_color;
	while (nb_pixels)
	{
		*(temp_indice_color) = *(temp_indice_color) + color_indice;
		if ((float)v1.x + 800 > 0 && (float)v1.y + 750 > 0)
			ft_mlx_put_pixel(img, (float)v1.x + 800, (float)v1.y + 750, color_tab[*(temp_indice_color)]);
		v1.x = v1.x + delta_x;
		v1.y = v1.y + delta_y;
		nb_pixels = nb_pixels - 1;
	}
	free(temp_indice_color);
}
