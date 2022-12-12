/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:29:12 by vde-leus          #+#    #+#             */
/*   Updated: 2022/12/12 15:59:55 by vde-leus         ###   ########.fr       */
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
# include <time.h>

# ifndef ZOOM
#  define ZOOM 10
# endif

# ifndef COLOR_MIN
#  define COLOR_MIN 0x0000FF
# endif

# ifndef PI
#  define PI 3.1495
# endif

# ifndef COLOR_TAB_SIZE
#  define COLOR_TAB_SIZE 100
# endif

/////
# ifndef THETA_Y
#  define THETA_Y 65
# endif
/////

# ifndef THETA_X
#  define THETA_X 60
# endif

# ifndef THETA2
#  define THETA2 30
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
int			*ft_generate_color_tab(void);
int			ft_color_vertex(t_map *map, int hauteur_z, int *color_tab, int *indice_vertex);

////////////////////////////////// VERTEX.C ///////////////////////////////////

typedef struct s_vertex
{
	float	x;
	float	y;
	float	z;
	int		color;
	int		*indice_tab_color;
}t_vertex;

// t_vertex	*ft_generate_vertex(t_data *img, t_map *map, size_t j, int *color_tab);
// t_vertex	**ft_generate_vertex_map(t_data *img, t_map *map);
// void		ft_centrage_vertex_map(t_vertex **vertex_map, t_map *map);

////////////////////////////////// MAIN.C ///////////////////////////////////

typedef struct s_data
{
	void		*mlx;
	void		*image;
	void		*black;
	void		*window;
	char		*address;
	char		*address_black;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			zoom;
	int			angle_rotation_y;
	int			angle_rotation_plan;
	t_map		*map;
	t_vertex	**vertex;
}t_data;

void		ft_mlx_put_pixel(t_data *img, int x, int y, int color);
void		ft_mlx_put_pixel_black(t_data *img, int x, int y);
t_data		*ft_init_data(char *map_name);
void		ft_draw(t_data *img);
void		ft_draw_heb(t_data *img);
void		ft_rotation_plane(t_data *img);
void		ft_rotation_axe_x(t_data *img);
void		ft_rotation_axe_y(t_data *img);
int 		mouse_event(int button, int x, int y, void *param);
int			ft_get_transfo(int key, t_data *img);
t_vertex	*ft_generate_vertex(t_map *map, size_t j, int *color_tab);
t_vertex	**ft_generate_vertex_map(t_map *map);
void		ft_centrage_vertex_map(t_vertex **vertex_map, t_map *map);
void		ft_zoom(t_data *img);
void		ft_black_screen(t_data *img);

////////////////////////////////// LINE.C ///////////////////////////////////

int			ft_color_indice_pixel(t_vertex v1, t_vertex v2, float nb_pixels);
int			ft_get_color(int *temp, t_vertex v1, t_vertex v2, float nb_pixels);
void		ft_draw_line(t_data *img, t_vertex v1, t_vertex v2, int *color_tab);

#endif