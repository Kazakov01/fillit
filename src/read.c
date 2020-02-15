/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquincy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 23:49:50 by jquincy           #+#    #+#             */
/*   Updated: 2019/11/21 19:06:12 by jquincy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <unistd.h>

void	min_max(char *str, t_point *min, t_point *max)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (i / 5 < min->y)
				min->y = i / 5;
			if (i / 5 > max->y)
				max->y = i / 5;
			if (i % 5 < min->x)
				min->x = i % 5;
			if (i % 5 > max->x)
				max->x = i % 5;
		}
		i++;
	}
}

t_tetr	*get_piece(char *str, char val)
{
	t_point		*mi;
	t_point		*max;
	char		**pos;
	int			i;
	t_tetr		*tetr;

	mi = point_new(3, 3);
	max = point_new(0, 0);
	min_max(str, mi, max);
	pos = ft_memalloc(sizeof(char *) * (max->y - mi->y + 1));
	i = 0;
	while (i < max->y - mi->y + 1)
	{
		pos[i] = ft_strnew(max->x - mi->x + 1);
		ft_strncpy(pos[i], str + (mi->x) + (i + mi->y) * 5, max->x - mi->x + 1);
		i++;
	}
	tetr = tetr_new(pos, max->x - mi->x + 1, max->y - mi->y + 1, val);
	ft_memdel((void **)&mi);
	ft_memdel((void **)&max);
	return (tetr);
}

int		connect(char *str)
{
	int fig;
	int i;

	fig = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				fig++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				fig++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				fig++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				fig++;
		}
		i++;
	}
	return (fig == 6 || fig == 8);
}

int		chnumb(char *str, int numb)
{
	int i;
	int fig;

	fig = 0;
	i = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (!(str[i] == '#' || str[i] == '.'))
				return (1);
			if (str[i] == '#' && ++fig > 4)
				return (2);
		}
		else if (str[i] != '\n')
			return (3);
		i++;
	}
	if (numb == 21 && str[20] != '\n')
		return (4);
	if (!connect(str))
		return (5);
	return (0);
}

t_list	*read_tetr(int fd)
{
	char	*buf;
	int		numb;
	t_list	*list;
	t_tetr	*tetr;
	char	cur;

	buf = ft_strnew(21);
	list = NULL;
	cur = 'A';
	while ((numb = read(fd, buf, 21)) >= 20)
	{
		if (chnumb(buf, numb) != 0
				|| (tetr = get_piece(buf, cur++)) == NULL)
		{
			ft_memdel((void **)&buf);
			return (free_list(list));
		}
		ft_lstadd(&list, ft_lstnew(tetr, sizeof(t_tetr)));
		ft_memdel((void **)&tetr);
	}
	ft_memdel((void **)&buf);
	if (numb != 0)
		return (free_list(list));
	ft_lstrev(&list);
	return (list);
}
