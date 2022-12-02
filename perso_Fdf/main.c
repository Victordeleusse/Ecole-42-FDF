/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:52:38 by vde-leus          #+#    #+#             */
/*   Updated: 2022/12/02 16:12:55 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_data	*ft_init_data(char *map_name, void *mlx)
{
	t_data	*img;
	int	i = 0;
	int	j = 0;

	img = (t_data *)malloc(sizeof(t_data));
	if (!img)
		return (NULL);
	img->map = ft_generate_map(map_name);
	while (i < img->map->height)
	{
		j = 0;
		while (j < img->map->width)
		{	
			printf("%-3d", img->map->map_int[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	img->image = mlx_new_image(mlx, img->map->width * ZOOM, img->map->height * ZOOM);
	img->address = mlx_get_data_addr(img->image, &img->bits_per_pixel, &img->line_length, &img->endian);
	return (img);
}

void	ft_mlx_put_pixel(t_data *img, int x, int y, int color)
{
	int		offset;
	char	*pixel_address;

	// color = 
	offset = (x * (img->bits_per_pixel / 8) + y * img->line_length);
	pixel_address = img->address + offset;
	*(int *)pixel_address = color;
}

void	ft_draw(t_data *img, void *mlx, void *window)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	while (j < img->map->height * ZOOM)
	{
		i = 0;
		while (i < img->map->width * ZOOM)
		{
			if (img->map->map_int[j / ZOOM][i / ZOOM] == 0)
			{	
				k = 0;
				while (k < ZOOM)
				{	
					ft_mlx_put_pixel(img, i + k, j, 0x0000ff);
					ft_mlx_put_pixel(img, i + ZOOM, j + k, 0x0000ff);
					ft_mlx_put_pixel(img, i + k, j + ZOOM, 0x0000ff);
					ft_mlx_put_pixel(img, i, j + k, 0x0000ff);
					k++;
				}
			}
			if (img->map->map_int[j / ZOOM][i / ZOOM] != 0)
			{	
				k = 0;
				while (k < ZOOM)
				{	
					ft_mlx_put_pixel(img, i + k, j, 0xff0000);
					ft_mlx_put_pixel(img, i + ZOOM, j + k, 0xff0000);
					ft_mlx_put_pixel(img, i + k, j + ZOOM, 0xff0000);
					ft_mlx_put_pixel(img, i, j + k, 0xff0000);
					k++;
				}
			}
			i = i + ZOOM;
		}
		j = j + ZOOM;
	}
	mlx_put_image_to_window(mlx, window, img->image, 0, 0);
	mlx_loop(mlx);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_window;
	t_data	*img;
	int		max;
	int		min;

	mlx = mlx_init();
	img = ft_init_data("test_map.txt", mlx);
	min = ft_min_map(img->map);
	max = ft_max_map(img->map);
	printf("min : %d\n", min);
	printf("max : %d\n", max);
	mlx_window = mlx_new_window(mlx, img->map->height + 500, img->map->width + 500, "FdF");
	ft_draw(img, mlx, mlx_window);
	return (0);
}

// int	main(void)
// {
// 	ft_draw();
// 	return (0);
// }
