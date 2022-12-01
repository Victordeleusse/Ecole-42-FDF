/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:29:12 by vde-leus          #+#    #+#             */
/*   Updated: 2022/11/30 19:33:09 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H


///////////////////////////////////// LIBRARIES /////////////////////////////////////

# include <mlx.h>
# include <libft_fdf.h>

# include <stdlib.h>
# include <stdio.h>
# include <string.h>

///////////////////////////////////// STRUCTURES /////////////////////////////////////


typedef struct	s_data 
{
	void	*image;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_data;

///////////////////////////////////// COLORS /////////////////////////////////////

# define BLACK 0x000000
# define WHITE 0xffffff
# define RED 0xff0000
# define GREEN 0x00ff00
# define BLUE 0x0000ff
# define YELLOW 0xffff00
# define ORANGE 0xFF6600
# define PURPLE 0x6600FF

typedef struct s_color_rgb
{
	int	r;
	int	g;
	int	b;
}t_color_rgb;

# ifndef bites_per_pixel
# 	define bites_per_pixel 8
# endif

#endif