/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:52:38 by vde-leus          #+#    #+#             */
/*   Updated: 2022/12/05 18:31:14 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_data	*ft_init_data(char *map_name)
{
	t_data	*img;
	int	i = 0;
	int	j = 0;

	img = (t_data *)malloc(sizeof(t_data));
	if (!img)
		return (NULL);
	img->mlx = mlx_init();
	img->map = ft_generate_map(map_name);
	while (j < img->map->height)
	{
		i = 0;
		while (i < img->map->width)
		{	
			printf("%-3d", img->map->map_int[j][i]);
			i++;
		}
		printf("\n");
		j++;
	}
	img->image = mlx_new_image(img->mlx, img->map->width * ZOOM, \
					img->map->height * ZOOM);
	img->address = mlx_get_data_addr(img->image, &img->bits_per_pixel, \
					&img->line_length, &img->endian);
	img->window = mlx_new_window(img->mlx, img->map->width + 1500, \
				img->map->height + 1500, "FdF");
	img->vertex = ft_generate_vertex_map(img->map);
	printf("\n\n\n");
	i = 0;
	j = 0;
	while (j < img->map->height)
	{
		i = 0;
		while (i < img->map->width)
		{	
			printf("Position dans l espace : x = %d, y = %d, z = %d ||", img->vertex[j][i].x, img->vertex[j][i].y, img->vertex[j][i].z);
			i++;
		}
		printf("\n");
		j++;
	}
	return (img);
}

void	ft_mlx_put_pixel(t_data *img, int x, int y, int color)
{
	int			offset;
	char		*pixel_address;
	t_color_rgb	rgb;

	offset = (x * (img->bits_per_pixel / 8) + y * img->line_length);
	pixel_address = img->address + offset;
	*(int *)pixel_address = color;
}

void	ft_draw(t_data *img)
{
	int	i;
	int	j;

	j = 0;
	while (j < img->map->height -1)
	{
		i = 0;
		while (i < img->map->width -1)
		{
			ft_draw_line(img, img->vertex[j][i].x, img->vertex[j][i].y, img->vertex[j][i + 1].x, img->vertex[j][i + 1].y, ft_color_pixel(img->map, i, j));
			ft_draw_line(img, img->vertex[j][i].x, img->vertex[j][i].y, img->vertex[j + 1][i].x, img->vertex[j + 1][i].y, ft_color_pixel(img->map, i, j));
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(img->mlx, img->window, img->image, 0, 0);
	mlx_loop(img->mlx);
}

int	main(void)
{
	void	*mlx_window;
	t_data	*img;
	int		max;
	int		min;

	img = ft_init_data("test_map.txt");
	min = ft_min_map(img->map);
	max = ft_max_map(img->map);
	printf("min : %d\n", min);
	printf("max : %d\n", max);
	ft_draw(img);
	return (0);
}

// int	main(void)
// {
// 	ft_draw();
// 	return (0);
// }
