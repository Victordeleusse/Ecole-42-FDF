/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:52:38 by vde-leus          #+#    #+#             */
/*   Updated: 2022/12/08 12:09:12 by vde-leus         ###   ########.fr       */
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
	img->image = mlx_new_image(img->mlx, img->map->width * ZOOM + 900, \
					img->map->height * ZOOM + 400);
	img->address = mlx_get_data_addr(img->image, &img->bits_per_pixel, \
					&img->line_length, &img->endian);
	img->window = mlx_new_window(img->mlx, img->map->width + 1500, \
				img->map->height + 900, "FdF");
	img->vertex = ft_generate_vertex_map(img->map);
	printf("\n\n");
	ft_rotation(img);
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
		printf("\n\n");
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
	size_t		r;
	// t_vertex	v1_test;
	// t_vertex	v2_test;

	// v1_test.color = COLOR_MIN;
	// v1_test.x = -200;
	// v2_test.x = 200;
	// v1_test.y = 0;
	// v2_test.y = 100;
	// v1_test.z = 0;
	// v2_test.z = 8;
	printf("\n\n");
	tab_color = ft_generate_color_tab();
	r = 0;
	while (tab_color[r])
	{
		// printf("Les couleurs du tableaux : %d\n", tab_color[r]);
		r++;
	}
	// v1_test.indice_tab_color = ft_calloc((size_t) sizeof(int), (size_t) 1);
	// v2_test.indice_tab_color = ft_calloc((size_t) sizeof(int), (size_t) 1);
	// *(v1_test.indice_tab_color) = 99;
	// *(v2_test.indice_tab_color) = 0;
	
	// v2_test.color = ft_color_vertex(img->map, v2_test.z, tab_color, 0);
	// printf("Couleur de v1 : %d\n", v1_test.color);
	// printf("Couleur de v2 : %d\n", v2_test.color);
	// printf("indice de la couleur de v1 : %d\n", *(v1_test.indice_tab_color));
	// printf("\n\nIndice : %d\n", *img->vertex[2][2].indice_tab_color);
	j = 0;
	while (j < img->map->height -1)
	{
		i = 0;
		printf("Ligne j : %ld\n", j);
		while (i < img->map->width -1)
		{
			ft_draw_line(img, img->vertex[j][i], img->vertex[j][i + 1], tab_color);
			ft_draw_line(img, img->vertex[j][i], img->vertex[j + 1][i], tab_color);
			i++;
		}
		j++;
		printf("\n");
	}
	// ft_draw_line(img, v1_test, v2_test, tab_color);
	mlx_put_image_to_window(img->mlx, img->window, img->image, 100, 100);
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
