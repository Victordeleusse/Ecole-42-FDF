/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:29:12 by vde-leus          #+#    #+#             */
/*   Updated: 2022/12/22 11:19:40 by vde-leus         ###   ########.fr       */
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

# ifndef THETA_X
#  define THETA_X 60
# endif

# ifndef THETA2
#  define THETA2 30
# endif

////////////////////////////////// COLOR.C ///////////////////////////////////

/* Fonctions non utilisees dans ce projet */

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

/* Retranscription de la map composee de char, recue en fichier .txt, 
// en une map compose de int, format int ** 
// Generation d une structure t_map composee de cette map d'int, et
// de ses dimensions */

typedef struct s_map
{
	char	*name;
	size_t	height;
	size_t	width;
	int		**map_int;
}t_map;

size_t		ft_width(char *str);
size_t		ft_width_max(size_t height, char *map_name);
t_map		*ft_init_map(char *nom);
int			*ft_line_int(char *str, size_t width);
t_map		*ft_generate_map(char *nom);

//////////////////////////////// PIXEL_COLOR.C /////////////////////////////////

/* Generation d une color tab, en fonction COLOR_MIN et de la 
// granularite souhaitee, COLOR_TAB_SIZE : plus ce nombre sera eleve, 
// plus la difference de couleur entre chaque hauteur sera "faible"
*/

/* La fonction color vertex va permettre d allouer a chaque point vertex 
// une couleur en fonction de son indice dans la tab -> recuperation de l indice
// par jeux de pointeur */

int			ft_max_map(t_map *map);
int			ft_min_map(t_map *map);
int			*ft_generate_color_tab(void);
int			ft_color_vertex(t_map *map, int hauteur_z, \
				int *color_tab, int *indice_vertex);

////////////////////////////////// VERTEX.C ///////////////////////////////////

/* Generation d un tableau de vertex -> points "reels" geographiques : des 
// coordonnees, un indice dans la tab et la couleur correspondante */

/* Le travail ne s effectue plus sur la t_map*/

typedef struct s_vertex
{
	float	x;
	float	y;
	float	z;
	int		color;
	int		*indice_tab_color;
}t_vertex;

t_vertex	*ft_generate_vertex(t_map *map, size_t j, int *color_tab);
t_vertex	**ft_generate_vertex_map(t_map *map);

////////////////////////////////// MAIN.C ///////////////////////////////////

/* Initialisation de ma stucture de travail t_data */

/* La fonction d initialisation fixe les parametres de base */

/* La fonction mlx_pack permet de gerer l affichage ainsi que les 
// evenements geres par les fonctions implementees dans la minilibx */

typedef struct s_data
{
	void		*mlx;
	void		*image;
	void		*window;
	char		*address;
	float		*p1;
	float		*p2;
	int			*tab_color;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	float		zoom;
	int			angle_rotation_y;
	int			angle_rotation_plan;
	t_map		*map;
	t_vertex	**vertex;
}t_data;

t_data		*ft_init_data(char *map_name);
void		ft_mlx_pack(t_data *img);

////////////////////////////////// HOOK.C ///////////////////////////////////

/* Fonctions qui permettent la transformation des parametres du trace suite 
// a l action de l utilisateur sur le keyboard / mouse ou window */

/* Rappel des fonctions de la mlx afin d afficher une nouvelle image, modifiee
// par les actions de l utilisateur */

void		ft_key_action(int key, t_data *img);
int			ft_get_transfo(int key, t_data *img);
int			ft_get_transfo_mouse(int button, int x, int y, t_data *img);
int			ft_get_transfo_window(t_data *img);
void		ft_regenarate(t_data *img);

////////////////////////////////// PIXEL.C ///////////////////////////////////

/* Fonction permettant de colorer un pixel de la couleur entree en 
// parametre en fonction d un offset correspondant aux coordonnees 
// du pixel en question */

void		ft_mlx_put_pixel(t_data *img, int x, int y, int color);
void		ft_clear_window(t_data *img);

////////////////////////////////// DRAW.C ///////////////////////////////////

/* Fonctions faisant appel aux fonctions definies dans LINE.C 
// Selon l angle de vue, on tracera de la gauche vers la droite 
// ou de la droite vers la gauche */

/* La fonction finis_proper permet de tracer le contour manquant de notre 
// image */

void		ft_cond_draw(t_data *img, int i, int j, float z);
void		ft_cond_draw_heb(t_data *img, int i, int j, float z);
void		ft_draw(t_data *img);
void		ft_draw_heb(t_data *img);
void		ft_finish_proper(t_data *img, int *tab_color);

/////////////////////////////// TRANSFORMATION.C /////////////////////////////

/* Ensemble des fonctions liees a la transformations de la figure apres appel 
// des fonctions definies dans HOOK.C */

void		ft_rotation_plane(t_data *img);
void		ft_rotation_axe_x(t_data *img);
void		ft_rotation_axe_y(t_data *img);
void		ft_centrage_vertex_map(t_vertex **vertex_map, t_map *map);
void		ft_zoom(t_data *img);

////////////////////////////////// LINE.C ///////////////////////////////////

/* Fonctions permettant le trace de ligne entre 2 vertex -> coloration des 
// pixels entre ces points pour tracer la ligne avec evolution de la couleur 
// en fonction des hauteurs de ces 2 vertexs */

/* Les 2 dernieres fonctions sont affiliees au hook mouse : enregistrement des
// coordonnees des points sur lesquels la souris a cliquee et generation d une 
// ligne de couleur predefinie entre ces points */

int			ft_color_indice_pixel(t_vertex v1, t_vertex v2, float nb_pixels);
int			ft_get_color(int *temp, t_vertex v1, t_vertex v2, float nb_pixels);
void		ft_draw_line(t_data *img, t_vertex v1, t_vertex v2, int *color_tab);
float		*ft_generate_doublette(float x, float y);
void		ft_draw_red_line(t_data *img);

////////////////////////////////// FREE.C ///////////////////////////////////

void		ft_free_vertex(t_data *img);
void		ft_free_map(t_data *img);
void		ft_free_data(t_data *img);

#endif