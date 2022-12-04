/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:25:53 by vde-leus          #+#    #+#             */
/*   Updated: 2022/12/04 16:22:35 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Map generation from a .txt file
// Following width_max, the entire map will be filled by 0 for "missing value"

#include "fdf.h"

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

size_t	ft_width_max(size_t height, char *map_name)
{
	int		fd;
	size_t	i;
	size_t	j;
	size_t	width_max;

	i = 0;
	width_max = 0;
	fd = open(map_name, O_RDONLY);
	while (i < height)
	{
		j = ft_width(get_next_line(fd));
		if (width_max < j)
			width_max = j;
		++i;
	}
	return (width_max);
}

t_map	*ft_init_map(char *map_name)
{
	int		fd;
	int		*line;
	size_t	i;
	size_t	j;
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->name = map_name;
	map->width = 0;
	map->height = 0;
	fd = open(map_name, O_RDONLY);
	while (get_next_line(fd))
		map->height++;
	map->width = ft_width_max(map->height, map_name);
	map->map_int = ft_calloc((size_t) sizeof(int *), map->height);
	if (!map->map_int)
		return (NULL);
	return (map);
}

int	*ft_line_int(char *str, size_t width)
{
	size_t	i;
	int		*line;
	char	**tab;

	tab = ft_split(str, ' ');
	line = ft_calloc(sizeof(int), width);
	if (!line)
		return (NULL);
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
