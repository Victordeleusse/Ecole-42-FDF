/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:29:12 by vde-leus          #+#    #+#             */
/*   Updated: 2022/12/01 18:59:33 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H


////////////////////////////////// LIBRARIES //////////////////////////////////

# include <mlx.h>
# include <libft_fdf.h>

# include <stdlib.h>
# include <stdio.h>
# include <string.h>

////////////////////////////////// COLOR.C ///////////////////////////////////

typedef struct s_color_rgb
{
	int	r;
	int	g;
	int	b;
}t_color_rgb;

int		ft_new_color(int color, int blue, int green, int red);

////////////////////////////////// MAP.C ///////////////////////////////////

typedef struct s_map
{
	char	*name;
	size_t	height;
	size_t	length;
	int		**map_int;
}t_map;

t_map	ft_init_map(char *nom);
int		*ft_line_int(char *str, size_t length);
t_map	ft_generate_map(char *nom);

////////////////////////////////// MAIN.C ///////////////////////////////////

typedef struct s_data
{
	void	*image;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_map	map;
}t_data;

void	ft_mlx_put_pixel(t_data img, int x, int y, int color);

////////////////////////////////// COLORS /////////////////////////////////////

# define BLACK 0x000000
# define WHITE 0xffffff
# define RED 0xff0000
# define GREEN 0x00ff00
# define BLUE 0x0000ff
# define YELLOW 0xffff00
# define ORANGE 0xFF6600
# define PURPLE 0x6600FF


#endif