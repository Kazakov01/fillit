/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquincy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 23:28:01 by jquincy           #+#    #+#             */
/*   Updated: 2019/09/21 06:27:19 by jquincy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *d;
	unsigned char *s;
	unsigned char sm;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	sm = (unsigned char)c;
	while (n--)
	{
		*d++ = *s++;
		if (*(d - 1) == sm)
		{
			return (d);
		}
	}
	return (NULL);
}
