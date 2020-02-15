/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquincy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 23:56:06 by jquincy           #+#    #+#             */
/*   Updated: 2019/11/21 19:12:55 by jquincy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

t_list		*free_list(t_list *list)
{
	t_tetr	*tetr;
	t_list	*next;

	while (list)
	{
		tetr = (t_tetr *)list->content;
		next = list->next;
		free_tetr(tetr);
		ft_memdel((void **)&list);
		list = next;
	}
	return (NULL);
}

void		free_tetr(t_tetr *tetr)
{
	int y;

	y = 0;
	while (y < tetr->len)
	{
		ft_memdel((void **)(&(tetr->pos[y])));
		y++;
	}
	ft_memdel((void **)(&(tetr->pos)));
	ft_memdel((void **)&tetr);
}

t_tetr		*tetr_new(char **pos, int wid, int len, char val)
{
	t_tetr		*tetr;

	tetr = ft_memalloc(sizeof(t_tetr));
	tetr->pos = pos;
	tetr->wid = wid;
	tetr->len = len;
	tetr->val = val;
	return (tetr);
}

t_point		*point_new(int x, int y)
{
	t_point		*point;

	point = ft_memalloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	return (point);
}
