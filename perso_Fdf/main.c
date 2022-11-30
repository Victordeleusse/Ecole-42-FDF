/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:52:38 by vde-leus          #+#    #+#             */
/*   Updated: 2022/11/30 16:59:23 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define bites_per_pixel 100

void    ft_mlx_put_pixel(t_data img, int x, int y, int color)
{
    int     offset;
    char    *pixel_address;

    offset = (x * (img.bits_per_pixel/8) + y * img.line_length);
    pixel_address = img.address + offset;
    *(int *)pixel_address = color;
}

int main(void)
{
    void    *mlx;
    void    *mlx_window;
    t_data  img;
    int     i;
    int     j;

    // img.bits_per_pixel = 4;
    // img.line_length = 400;
    i = 0;
    j = 0;
    mlx = mlx_init();
    mlx_window = mlx_new_window(mlx, 500, 500, "First");
    img.image = mlx_new_image(mlx, 1000, 1000);
    img.address = mlx_get_data_addr(img.image, &img.bits_per_pixel, &img.line_length, &img.endian);
    while (j < 100)
    {    
        ft_mlx_put_pixel(img, 100 - 3 * (i * i, j, RED));
        ft_mlx_put_pixel(img, 100 + i, j, RED);
        i++;
        j++;
    }
    while (j < 200)
    {    
        ft_mlx_put_pixel(img, 100 - i, j, BLUE);
        ft_mlx_put_pixel(img, 100 + i, j, BLUE);
        i--;
        j++;
    }
    mlx_put_image_to_window(mlx, mlx_window, img.image, 150, 100);
    mlx_loop(mlx);
}