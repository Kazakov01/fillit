/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquincy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 23:36:55 by jquincy           #+#    #+#             */
/*   Updated: 2019/09/19 05:00:32 by jquincy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *str;
	unsigned char sm;

	str = (unsigned char *)s;
	sm = (unsigned char)c;
	while (n--)
	{
		if (*str == sm)
		{
			return (str);
		}
		str++;
	}
	return (NULL);
}
