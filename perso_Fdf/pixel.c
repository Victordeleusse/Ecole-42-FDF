/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:39:10 by vde-leus          #+#    #+#             */
/*   Updated: 2022/12/21 17:39:53 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mlx_put_pixel(t_data *img, int x, int y, int color)
{
	int			offset;
	char		*pixel_address;

	offset = (x * (img->bits_per_pixel / 8) + y * img->line_length);
	pixel_address = img->address + offset;
	*(int *)pixel_address = color;
}

void	ft_clear_window(t_data *img)
{
	int	i;
	int	j;

	j = 0;
	while (j < 1400)
	{
		i = 0;
		while (i < 1700)
			ft_mlx_put_pixel(img, i++, j, 0x000000);
	j++;
	}	
}
