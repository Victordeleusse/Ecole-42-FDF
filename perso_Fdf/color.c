/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:16:07 by vde-leus          #+#    #+#             */
/*   Updated: 2022/11/30 20:05:05 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*	
//	RGB transformation : the idea is to be able to change color by adding more
// 	of blue, more of red or more of green to our color. 
//	
//	Colors came from 0 to 255 (FF equivalent in hexadecimal) -> fit in an int as int 
//	is 4 bytes - also fit with unsigned char (each byte contains 2^8 = 256 values) when
//	a char comes from -128 to 127, an unsigned char comes from 0 to 255.
//	
*/

#include "fdf.h"

t_color_rgb ft_transformation(int color)
{
	if (color < 256)
	{
		
	}
	else if (color < 65281)
	{
		
	}
	else
	{
		
	}
	
}
