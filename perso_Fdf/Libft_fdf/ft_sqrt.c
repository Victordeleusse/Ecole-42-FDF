/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:25:17 by vde-leus          #+#    #+#             */
/*   Updated: 2022/12/05 12:12:22 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt(int nb)
{
	int		resultat;
	int		increment;
	float	an;
	float	an1;

	increment = 0;
	an1 = 0;
	an = (float)nb;
	while (increment < 15)
	{
		an1 = (an + (nb) / an) / 2;
		an = an1;
		increment++;
	}	
	resultat = (int)an1;
	return (resultat);
}

// int	main(void)
// {
// 	int	nb = 7920200;
// 	int	resultat;

// 	resultat = ft_sqrt(nb);
// 	printf("resultat : %d", resultat);
// 	return (0);
// }
