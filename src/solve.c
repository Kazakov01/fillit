/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquincy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 23:50:00 by jquincy           #+#    #+#             */
/*   Updated: 2019/11/21 18:55:18 by jquincy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include "fillit.h"

int		solve_map(t_map *map, t_list *list)
{
	int			x;
	int			y;
	t_tetr		*tetr;

	if (list == NULL)
		return (1);
	y = 0;
	tetr = (t_tetr *)(list->content);
	while (y < map->size - tetr->len + 1)
	{
		x = 0;
		while (x < map->size - tetr->wid + 1)
		{
			if (place(tetr, map, x, y))
			{
				if (solve_map(map, list->next))
					return (1);
				else
					set_piece(tetr, map, point_new(x, y), '.');
			}
			x++;
		}
		y++;
	}
	return (0);
}

int		hsqrt(int n)
{
	int size;

	size = 2;
	while (size * size < n)
		size++;
	return (size);
}

t_map	*solve(t_list *list)
{
	t_map	*map;
	int		size;

	size = hsqrt(ft_lstcount(list) * 4);
	map = map_new(size);
	while (!solve_map(map, list))
	{
		size++;
		free_map(map);
		map = map_new(size);
	}
	return (map);
}
