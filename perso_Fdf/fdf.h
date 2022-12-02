/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:29:12 by vde-leus          #+#    #+#             */
/*   Updated: 2022/12/02 16:26:46 by vde-leus         ###   ########.fr       */
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

# ifndef ZOOM
#  define ZOOM 25
# endif

# ifndef COLOR_MIN
#  define COLOR_MIN 0x000077
# endif

# ifndef COLOR_MAX
#  define COLOR_MAX 0x770000
# endif

////////////////////////////////// COLOR.C ///////////////////////////////////

typedef struct s_color_rgb
{
	int	r;
	int	g;
	int	b;
}t_color_rgb;

t_color_rgb	ft_get_rgb(int color);

////////////////////////////////// MAP.C ///////////////////////////////////

// map[j][i] avec j = height et i = width

typedef struct s_map
{
	char	*name;
	size_t	height;
	size_t	width;
	int		**map_int;
}t_map;

t_map		*ft_init_map(char *nom);
int			*ft_line_int(char *str, size_t width);
t_map		*ft_generate_map(char *nom);

//////////////////////////////// PIXEL_COLOR.C /////////////////////////////////

int			ft_max_map(t_map *map);
int			ft_min_map(t_map *map);

////////////////////////////////// MAIN.C ///////////////////////////////////

typedef struct s_data
{
	void	*image;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_map	*map;
}t_data;

void		ft_mlx_put_pixel(t_data *img, int x, int y, int color);
t_data		*ft_init_data(char *map_name, void *mlx);
void		ft_draw(t_data *img, void *mlx, void *window);

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