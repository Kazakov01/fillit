/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquincy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 19:19:39 by jquincy           #+#    #+#             */
/*   Updated: 2019/11/21 18:50:54 by jquincy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_memdel((void **)&(map->array[i]));
		i++;
	}
	ft_memdel((void **)&(map->array));
	ft_memdel((void **)&map);
}

void	print_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_putstr(map->array[i]);
		ft_putchar('\n');
		i++;
	}
}

t_map	*map_new(int size)
{
	t_map	*map;
	int		i;
	int		j;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->size = size;
	map->array = (char **)ft_memalloc(sizeof(char *) * size);
	i = 0;
	while (i < size)
	{
		map->array[i] = ft_strnew(size);
		j = 0;
		while (j < size)
		{
			map->array[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

int		place(t_tetr *tetr, t_map *map, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < tetr->wid)
	{
		j = 0;
		while (j < tetr->len)
		{
			if (tetr->pos[j][i] == '#' && map->array[y + j][x + i] != '.')
				return (0);
			j++;
		}
		i++;
	}
	set_piece(tetr, map, point_new(x, y), tetr->val);
	return (1);
}

void	set_piece(t_tetr *tetr, t_map *map, t_point *point, char c)
{
	int i;
	int j;

	i = 0;
	while (i < tetr->wid)
	{
		j = 0;
		while (j < tetr->len)
		{
			if (tetr->pos[j][i] == '#')
				map->array[point->y + j][point->x + i] = c;
			j++;
		}
		i++;
	}
	ft_memdel((void **)&point);
}
