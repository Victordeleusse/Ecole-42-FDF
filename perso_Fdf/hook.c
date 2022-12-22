/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:56:14 by vde-leus          #+#    #+#             */
/*   Updated: 2022/12/22 12:06:31 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_key_action(int key, t_data *img)
{
	if (key == 97)
		img->angle_rotation_plan = img->angle_rotation_plan + 10;
	if (key == 115)
		img->angle_rotation_plan = img->angle_rotation_plan - 10;
	if (key == 122)
		img->zoom = img->zoom + 2;
	if (key == 100)
		img->zoom = img->zoom - 2;
	if (key == 113)
		img->angle_rotation_y = img->angle_rotation_y + 10;
	if (key == 119)
		img->angle_rotation_y = img->angle_rotation_y - 10;
	if (key == 65361)
		img->dx = img->dx - 1;
	if (key == 65363)
		img->dx = img->dx + 1;
	if (key == 65362)
		img->dy = img->dy - 1;
	if (key == 65364)
		img->dy = img->dy + 1;
	if (key == 65307)
	{
		ft_group_free(img);
		return ;
	}
}

int	ft_get_transfo_mouse(int button, int x, int y, t_data *img)
{
	ft_clear_window(img);
	mlx_clear_window(img->mlx, img->window);
	if (img->p1[0] == 0)
	{
		img->p1[0] = (float)x;
		img->p1[1] = (float)y;
	}
	else
	{
		img->p2[0] = (float)x;
		img->p2[1] = (float)y;
		ft_draw_red_line(img);
		img->p1[0] = 0;
		img->p1[1] = 0;
		img->p2[0] = 0;
		img->p2[1] = 0;
	}
	ft_regenarate(img);
	return (0);
}

int	ft_get_transfo(int key, t_data *img)
{
	int	i;
	int	j;

	ft_clear_window(img);
	mlx_clear_window(img->mlx, img->window);
	ft_key_action(key, img);
	if (img->angle_rotation_y > 180)
		img->angle_rotation_y = 180;
	if (img->angle_rotation_y < 0)
		img->angle_rotation_y = 0;
	ft_regenarate(img);
	return (0);
}

int	ft_get_transfo_window(t_data *img)
{
	if (img == NULL)
		;
	ft_free_vertex(img);
	ft_free_map(img);
	ft_free_data(img);
	free(img);
	exit(0);
	return (1);
}

void	ft_regenarate(t_data *img)
{
	ft_free_vertex(img);
	img->vertex = ft_generate_vertex_map(img->map);
	ft_centrage_vertex_map(img, img->vertex, img->map);
	ft_zoom(img);
	ft_rotation_axe_y(img);
	ft_rotation_plane(img);
	if (img->angle_rotation_y <= 130)
		ft_draw(img);
	else
		ft_draw_heb(img);
}
