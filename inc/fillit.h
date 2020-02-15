/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquincy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 19:28:20 by jquincy           #+#    #+#             */
/*   Updated: 2019/11/20 23:32:44 by jquincy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# include <string.h>

typedef struct	s_map
{
	int			size;
	char		**array;
}				t_map;

typedef struct	s_point
{
	int			y;
	int			x;
}				t_point;

typedef struct	s_tetr
{
	char		**pos;
	int			len;
	int			wid;
	char		val;
}				t_tetr;

int				place(t_tetr *tetr, t_map *map, int x, int y);
void			print_map(t_map *map);
void			free_map(t_map *map);
void			set_piece(t_tetr *tetr, t_map *map, t_point *point, char c);
void			free_tetr(t_tetr *tetr);
t_map			*map_new(int size);
t_map			*solve(t_list *list);
t_list			*read_tetr(int fd);
t_list			*free_list(t_list *list);
t_point			*point_new(int x, int y);
t_tetr			*tetr_new(char **pos, int len, int wid, char c);

#endif
