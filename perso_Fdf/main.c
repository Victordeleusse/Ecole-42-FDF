/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:52:38 by vde-leus          #+#    #+#             */
/*   Updated: 2022/12/22 11:53:33 by vde-leus         ###   ########.fr       */
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
	img->p1 = ft_generate_doublette(0, 0);
	img->p2 = ft_generate_doublette(0, 0);
	img->zoom = 51;
	img->angle_rotation_y = 100;
	img->angle_rotation_plan = 30;
	img->dx = 0;
	img->dy = 0;
	img->tab_color = ft_generate_color_tab();
	img->map = ft_generate_map(map_name);
	img->image = mlx_new_image(img->mlx, 4000, 3500);
	img->address = mlx_get_data_addr(img->image, &img->bits_per_pixel, \
					&img->line_length, &img->endian);
	img->window = mlx_new_window(img->mlx, 1700, 1400, "FdF");
	img->vertex = ft_generate_vertex_map(img->map);
	ft_centrage_vertex_map(img, img->vertex, img->map);
	ft_zoom(img);
	ft_rotation_axe_y(img);
	ft_rotation_plane(img);
	return (img);
}

void	ft_mlx_pack(t_data *img)
{
	mlx_put_image_to_window(img->mlx, img->window, img->image, 0, 0);
	mlx_hook(img->window, 17, 0, &ft_get_transfo_window, img);
	mlx_key_hook(img->window, &ft_get_transfo, img);
	mlx_mouse_hook(img->window, &ft_get_transfo_mouse, img);
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
	img = ft_init_data(argv[1]);
	if (img == NULL)
		return (0);
	ft_draw(img);
	return (0);
}
