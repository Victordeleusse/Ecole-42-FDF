/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:25:53 by vde-leus          #+#    #+#             */
/*   Updated: 2022/12/04 14:10:16 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>

size_t	ft_width(char *str)
{
	size_t	compteur;
	size_t	i;

	i = 0;
	compteur = 0;
	while (str != NULL && str[i] != '\0' && str[i] != '\n')
	{
		while (str[i] == ' ')
			i++;
		if (str[i] != '\0' && str[i] != '\n')
			compteur++;
		while (str[i] != ' ' && str[i] != '\0' && str[i] != '\n')
			i++;
	}
	return (compteur);
}

t_map	*ft_init_map(char *map_name)
{
	int		fd;
	int		*line;
	size_t	i;
	size_t	j;
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	map->name = map_name;
	map->width = 0;
	map->height = 0;
	fd = open(map_name, O_RDONLY);
	while (get_next_line(fd))
		map->height++;
	j = 0;
	i = 0;
	fd = open(map_name, O_RDONLY);
	while (i < map->height)
	{
		j = ft_width(get_next_line(fd));
		if (map->width < j)
			map->width = j;
		++i;
	}
	map->width = j;
	map->map_int = ft_calloc((size_t) sizeof(int *), map->height);
	return (map);
}

int	*ft_line_int(char *str, size_t width)
{
	size_t	i;
	int		*line;
	char	**tab;

	tab = ft_split(str, ' ');
	line = ft_calloc(sizeof(int), width);
	i = 0;
	while (tab[i] != 0)
	{
		line[i] = ft_atoi((const char *)tab[i]);
		i++;
	}
	return (line);
}

t_map	*ft_generate_map(char *map_name)
{
	size_t	j;
	int		fd;
	char	*str;
	t_map	*map;

	map = ft_init_map(map_name);
	j = 0;
	fd = open(map->name, O_RDONLY);
	while (j < map->height)
	{
		str = get_next_line(fd);
		map->map_int[j] = ft_line_int(str, map->width);
		j++;
	}
	return (map);
}

// int	main(void)
// {
// 	char	test[] = "a b c d\n";
// 	size_t	resultat;

// 	resultat = ft_width(test);
// 	printf("%ld", resultat);
// }
