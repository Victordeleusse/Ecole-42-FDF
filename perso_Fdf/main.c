/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:52:38 by vde-leus          #+#    #+#             */
/*   Updated: 2022/12/08 19:14:37 by vde-leus         ###   ########.fr       */
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
			// printf("%-3d", img->map->map_int[j][i]);
			i++;
		}
		// printf("\n");
		j++;
	}
	img->image = mlx_new_image(img->mlx, img->map->width * ZOOM + 1000, \
					img->map->height * ZOOM + 1000);
	img->address = mlx_get_data_addr(img->image, &img->bits_per_pixel, \
					&img->line_length, &img->endian);
	img->window = mlx_new_window(img->mlx, img->map->width + 1500, \
				img->map->height + 1000, "FdF");
	img->vertex = ft_generate_vertex_map(img->map);
	ft_centrage_vertex_map(img->vertex, img->map);
	i = 0;
	j = 0;
	while (j < img->map->height)
	{
		i = 0;
		while (i < img->map->width)
		{	
			// printf("Ligne j : %ld\n", j);
			// printf("Position dans l espace : x = %f, y = %f, z = %f, couleur = %d, indice = %d ||", img->vertex[j][i].x, img->vertex[j][i].y, img->vertex[j][i].z, img->vertex[j][i].color, *img->vertex[j][i].indice_tab_color);
			i++;
		}
		// printf("\n\n");
		j++;
	}
	i = 0;
	j = 0;
	// printf("\n\n");
	// ft_rotation_axe_y(img);
	// ft_rotation_axe_x(img);
	// ft_rotation_plane(img);
	while (j < img->map->height)
	{
		i = 0;
		while (i < img->map->width)
		{	
			// printf("Ligne j : %ld\n", j);
			// printf("Position dans l espace : x = %f, y = %f, z = %f, couleur = %d, indice = %d ||", img->vertex[j][i].x, img->vertex[j][i].y, img->vertex[j][i].z, img->vertex[j][i].color, *img->vertex[j][i].indice_tab_color);
			i++;
		}
		// printf("\n\n");
		j++;
	}
	return (img);
}

void	ft_mlx_put_pixel(t_data *img, int x, int y, int color)
{
	int			offset;
	char		*pixel_address;
	t_color_rgb	rgb;

	offset = (x  * (img->bits_per_pixel / 8) + y * img->line_length);
	pixel_address = img->address + offset;
	*(int *)pixel_address = color;
}

void	ft_draw(t_data *img)
{
	int	i;
	int	j;
	int	*tab_color;

	tab_color = ft_generate_color_tab();
	j = 0;
	while (j < img->map->height -1)
	{
		i = 0;
		printf("Ligne j : %ld\n", j);
		while (i < img->map->width - 1)
		{
			printf("Position dans l espace : x = %f, y = %f, z = %f ||\n", img->vertex[j][i].x, img->vertex[j][i].y, img->vertex[j][i].z);
			printf("Position dans l espace : x = %f, y = %f, z = %f ||\n", img->vertex[j][i + 1].x, img->vertex[j][i + 1].y, img->vertex[j][i].z);
			// printf("Position dans l espace : x = %f, y = %f, z = %f, couleur = %d, indice = %d ||", img->vertex[j][i].x, img->vertex[j][i].y, img->vertex[j][i].z, img->vertex[j][i].color, *img->vertex[j][i].indice_tab_color);
			ft_draw_line(img, img->vertex[j][i], img->vertex[j][i + 1], tab_color);
			printf("1ere trace\n");
			printf("Position dans l espace : x = %f, y = %f, z = %f ||\n", img->vertex[j][i].x, img->vertex[j][i].y, img->vertex[j][i].z);
			printf("Position dans l espace : x = %f, y = %f, z = %f ||\n", img->vertex[j + 1][i].x, img->vertex[j + 1][i].y, img->vertex[j][i].z);
			ft_draw_line(img, img->vertex[j][i], img->vertex[j + 1][i], tab_color);
			printf("2eme trace\n\n");
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

	img = ft_init_data("test_map.txt");
	ft_draw(img);
	return (0);
}
