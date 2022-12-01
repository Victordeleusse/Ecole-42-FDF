/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:25:53 by vde-leus          #+#    #+#             */
/*   Updated: 2022/12/01 17:43:02 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	ft_init_map(char *nom)
{
	int		fd;
	int		*line;
	size_t	i;
	size_t	j;
	t_map	map;

	map.name = nom;
	map.length = 0;
	fd = open(nom, O_RDONLY);
	while (get_next_line(fd))
		map.height++;
	fd = open(nom, O_RDONLY);
	while (i++ < map.height)
	{
		j = ft_strlen((const char *)get_next_line(fd)) - 1;
		if (map.length < j)
			map.length = j;
	}
	map.length = (map.length - 1) / 3 + 1;
	map.map_int = ft_calloc((size_t) sizeof(int *), map.height);
	return (map);
}

int	*ft_line_int(char *str, size_t length)
{
	size_t	i;
	int		*line;
	char	**tab;

	tab = ft_split(str, ' ');
	line = ft_calloc(sizeof(int), length);
	i = 0;
	while (tab[i] != 0)
	{
		line[i] = ft_atoi((const char *)tab[i]);
		i++;
	}
	return (line);
}

void	ft_generate_map_int(t_map map)
{
	size_t	i;
	int		fd;
	char	*str;

	i = 0;
	fd = open(map.name, O_RDONLY);
	while (i < map.height)
	{
		str = get_next_line(fd);
		map.map_int[i] = ft_line_int(str, map.length);
		i++;
	}
}

int	main(void)
{
	char	mape_name[] = "test_map.txt";
	t_map	map;
	size_t	i;
	size_t	j;

	i = 0;
	map = ft_init_map(mape_name);
	printf("longueur de la map : %ld\n\n\n", map.length);
	ft_generate_map_int(map);
	while (i < map.height)
	{
		j = 0;
		while (j < map.length)
		{	
			printf("%-3d", map.map_int[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	return (0);
}
