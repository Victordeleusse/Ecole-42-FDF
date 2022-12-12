/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:52:38 by vde-leus          #+#    #+#             */
/*   Updated: 2022/12/12 16:05:33 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_data	*ft_init_data(char *map_name)
{
	t_data	*img;

	img = (t_data *)malloc(sizeof(t_data));
	if (!img)
		return (NULL);
	img->mlx = mlx_init();
	img->zoom = 48;
	img->angle_rotation_y = 60;
	img->angle_rotation_plan = 30;
	img->map = ft_generate_map(map_name);
	img->image = mlx_new_image(img->mlx, 5200, 4500);
	// img->black = mlx_new_image(img->mlx, 5200, 4500);
	img->address = mlx_get_data_addr(img->image, &img->bits_per_pixel, \
					&img->line_length, &img->endian);
	// img->address_black = mlx_get_data_addr(img->black, &img->bits_per_pixel, \
					&img->line_length, &img->endian);
	// ft_black_screen(img);
	img->window = mlx_new_window(img->mlx, 1700, \
				1400, "FdF");
	img->vertex = ft_generate_vertex_map(img->map);
	ft_centrage_vertex_map(img->vertex, img->map);
	ft_zoom(img);
	ft_rotation_axe_y(img);
	ft_rotation_plane(img);
	return (img);
}

void	ft_mlx_put_pixel(t_data *img, int x, int y, int color)
{
	int			offset;
	char		*pixel_address;

	offset = (x * (img->bits_per_pixel / 8) + y * img->line_length);
	pixel_address = img->address + offset;
	*(int *)pixel_address = color;
}

// void	ft_mlx_put_pixel_black(t_data *img, int x, int y)
// {
// 	int			offset;
// 	char		*pixel_address;

// 	offset = (x * (img->bits_per_pixel / 8) + y * img->line_length);
// 	pixel_address = img->address_black + offset;
// 	*(int *)pixel_address = 0xFFFFFF;
// }

// void	ft_black_screen(t_data *img)
// {
// 	int	i;
// 	int	j;

// 	j = 0;
// 	while (j < 1400)
// 	{
// 		i = 0;
// 		while (i < 1700)
// 		{
// 			ft_mlx_put_pixel_black(img, i, j);
// 			i++;
// 		}
// 	j++;
// 	}	
// }

// int	mouse_event(int button, int x, int y, void *param)
// {
// 	ft_putnbr_fd(button, 1);
// 	printf("\n");
// 	ft_putnbr_fd(x, 1);
// 	printf("\n");
// 	ft_putnbr_fd(y, 1);
// 	printf("\n\n");
// }

int	ft_get_transfo(int key, t_data *img)
{
	int	i;
	int	j;

	// ft_putnbr_fd(key, 1);
	j = 0;
	while (j < 1400)
	{
		i = 0;
		while (i < 1700)
		{
			ft_mlx_put_pixel(img, i, j, 0x000000);
			i++;
		}
	j++;
	}	
	mlx_clear_window(img->mlx, img->window);
	if (key == 97)
		img->angle_rotation_plan = img->angle_rotation_plan + 10;
	if (key == 115)
		img->angle_rotation_plan = img->angle_rotation_plan - 10;
	if (key == 122)
		img->zoom = img->zoom + 3;
	if (key == 100)
		img->zoom = img->zoom - 3;
	if (key == 113)
		img->angle_rotation_y = img->angle_rotation_y + 10;
	if (key == 119)
		img->angle_rotation_y = img->angle_rotation_y - 10;
	if (key == 65307)
	{
		mlx_destroy_window(img->mlx, img->window);
		return (0);
	}
	// mlx_clear_window(img->mlx, img->window);
	// mlx_destroy_window(img->mlx, img->window);
	img->vertex = ft_generate_vertex_map(img->map);
	ft_centrage_vertex_map(img->vertex, img->map);
	ft_zoom(img);
	ft_rotation_axe_y(img);
	ft_rotation_plane(img);
	if (img->angle_rotation_y <= 140)
		ft_draw(img);
	else
		ft_draw_heb(img);
	return (0);
}

void	ft_draw(t_data *img)
{
	int	i;
	int	j;
	int	z;
	int	z_max;
	int	*tab_color;

	tab_color = ft_generate_color_tab();
	z = ft_min_map(img->map) * img->zoom / 12;
	z_max = ft_max_map(img->map) * img->zoom / 12;
	while(z <= z_max)
	{
		j = 0;
		while (j < img->map->height -1)
		{
			i = 0;
			while (i < img->map->width - 1)
			{
				if (img->vertex[j][i].z == z)
				{	
					ft_draw_line(img, img->vertex[j][i], img->vertex[j][i + 1], tab_color);
					ft_draw_line(img, img->vertex[j][i], img->vertex[j + 1][i], tab_color);
				}
				i++;
			}
			j++;
		}
		z++;
	}
	mlx_put_image_to_window(img->mlx, img->window, img->image, 0, 0);
	mlx_key_hook(img->window, &ft_get_transfo, img);
	mlx_loop(img->mlx);
}

void	ft_draw_heb(t_data *img)
{
	int	i;
	int	j;
	int	z;
	int	z_max;
	int	*tab_color;

	tab_color = ft_generate_color_tab();
	z = ft_min_map(img->map) * img->zoom / 12;
	z_max = ft_max_map(img->map) * img->zoom / 12;
	while(z <= z_max)
	{
		j = img->map->height - 2;
		while (j >= 0)
		{
			i = img->map->width - 2;
			while (i >= 0)
			{
				if (img->vertex[j][i].z == z)
				{	
					ft_draw_line(img, img->vertex[j][i + 1], img->vertex[j][i], tab_color);
					ft_draw_line(img, img->vertex[j + 1][i], img->vertex[j][i], tab_color);
				}
				i--;
			}
			j--;
		}
		z++;
	}
	mlx_put_image_to_window(img->mlx, img->window, img->image, 0, 0);
	mlx_key_hook(img->window, &ft_get_transfo, img);
	mlx_loop(img->mlx);
}

int	main(int argc, char **argv)
{
	void	*mlx_window;
	t_data	*img;

	if (argc != 2)
	{
		if (argc < 2)
			ft_putstr_fd("Missing file\n\n", 1);
		else
			ft_putstr_fd("Too many files\n\n", 1);
		ft_putstr_fd("Please enter 'make linux_run' to compile and then \
			'./FdF XXX.txt' to execute\n\n", 1);
		return (1);
	}
	if (!ft_init_data(argv[1]))
		return (ft_printf("Error occurred for file %s\n", argv[1]), 1);
	img = ft_init_data(argv[1]);
	ft_draw(img);
	return (0);
}
