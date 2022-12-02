/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:25:53 by vde-leus          #+#    #+#             */
/*   Updated: 2022/12/02 11:45:48 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	fd = open(map_name, O_RDONLY);
	while (get_next_line(fd))
		map->height++;
	j = 0;
	i = 0;
	fd = open(map_name, O_RDONLY);
	while (i++ < map->height)
	{
		j = ft_strlen((const char *)get_next_line(fd)) - 1;
		if (map->width < j)
			map->width = j;
	}
	map->width = (map->width - 1) / 3 + 1;
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
	size_t	i;
	int		fd;
	char	*str;
	t_map	*map;

	map = ft_init_map(map_name);
	i = 0;
	fd = open(map->name, O_RDONLY);
	while (i < map->height)
	{
		str = get_next_line(fd);
		map->map_int[i] = ft_line_int(str, map->width);
		i++;
	}
	return (map);
}

// int	main(void)
// {
// 	char	mape_name[] = "test_map.txt";
// 	size_t	i;
// 	size_t	j;	
// 	t_map	*map;

// 	i = 0;
// 	map = ft_generate_map(mape_name);
// 	while (i < map->height)
// 	{
// 		j = 0;
// 		while (j < map->width)
// 		{	
// 			printf("%-3d", map->map_int[i][j]);
// 			j++;
// 		}
// 		printf("\n");
// 		i++;
// 	}
// 	return (0);
// }
