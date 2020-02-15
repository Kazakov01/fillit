/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquincy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 04:44:27 by jquincy           #+#    #+#             */
/*   Updated: 2019/09/23 04:55:45 by jquincy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*cur;
	t_list	*frst;

	if (!lst)
		return (NULL);
	frst = f(lst);
	cur = frst;
	while (lst->next)
	{
		lst = lst->next;
		cur->next = f(lst);
		if (!(cur->next))
		{
			free(cur->next);
			return (NULL);
		}
		cur = cur->next;
	}
	return (frst);
}
