/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:29:12 by vde-leus          #+#    #+#             */
/*   Updated: 2022/12/04 18:09:55 by vde-leus         ###   ########.fr       */
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
#  define ZOOM 5
# endif

# ifndef COLOR_MIN
#  define COLOR_MIN 0xAAAF00
# endif

# ifndef COLOR_MAX
#  define COLOR_MAX 0xAADF00
# endif

////////////////////////////////// EVENTS.C ///////////////////////////////////

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}t_vars;


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

////////////////////////////////// MAIN.C ///////////////////////////////////

typedef struct s_data
{
	void	*mlx;
	void	*image;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_map	*map;
}t_data;

void		ft_mlx_put_pixel(t_data *img, int x, int y, int color);
t_data		*ft_init_data(char *map_name);
void		ft_draw(t_data *img, void *window);

#endif