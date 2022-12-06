/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:29:12 by vde-leus          #+#    #+#             */
/*   Updated: 2022/12/06 18:46:21 by vde-leus         ###   ########.fr       */
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

# include <math.h>

# ifndef ZOOM
#  define ZOOM 50
# endif

# ifndef COLOR_MIN
#  define COLOR_MIN 0x7D86FF
# endif

# ifndef COLOR_MAX
#  define COLOR_MAX 0xB0B6FF
# endif

# ifndef THETA
#  define THETA 0.85
# endif

////////////////////////////////// COLOR.C ///////////////////////////////////

typedef struct s_color_rgb
{
	int	r;
	int	g;
	int	b;
}t_color_rgb;

int			ft_get_red(int color);
int			ft_get_green(int color);
int			ft_get_blue(int color);
t_color_rgb	ft_get_rgb(int color);
int			ft_get_int_color(t_color_rgb rgb);

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
int			ft_new_color(int color_diff);
int			ft_color_pixel(t_map *map, int i, int j);

////////////////////////////////// VERTEX.C ///////////////////////////////////

typedef struct s_vertex
{
	float	x;
	float	y;
	float	z;
	int		color;
}t_vertex;

t_vertex	*ft_generate_vertex(t_map *map, size_t j);
t_vertex	**ft_generate_vertex_map(t_map *map);

////////////////////////////////// MAIN.C ///////////////////////////////////

typedef struct s_data
{
	void		*mlx;
	void		*image;
	void		*window;
	char		*address;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_map		*map;
	t_vertex	**vertex;
}t_data;

void		ft_mlx_put_pixel(t_data *img, int x, int y, int color);
t_data		*ft_init_data(char *map_name);
void		ft_draw(t_data *img);
void		ft_rotation(t_data *img);

////////////////////////////////// LINE.C ///////////////////////////////////

// void		ft_draw_line(t_data *img, float x_s, float y_s, float x_f, float y_f, int color);
void		ft_draw_line(t_data *img, t_vertex v1, t_vertex v2, int color);

#endif