/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquincy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 12:12:04 by jquincy           #+#    #+#             */
/*   Updated: 2019/09/21 14:11:08 by jquincy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *res;

	res = (t_list *)malloc(sizeof(*res));
	if (res == NULL)
		return (NULL);
	else
	{
		if (content != NULL)
		{
			res->content = (void *)ft_memalloc(sizeof(void) * content_size + 1);
			if (res->content == NULL)
				return (NULL);
			ft_memcpy(res->content, content, content_size);
			res->content_size = content_size;
		}
		else
		{
			res->next = NULL;
			res->content_size = 0;
		}
		res->next = NULL;
	}
	return (res);
}
