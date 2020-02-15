/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquincy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 04:26:12 by jquincy           #+#    #+#             */
/*   Updated: 2019/09/21 08:15:16 by jquincy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t reslen;
	size_t dstlen;

	dstlen = ft_strlen(dst);
	reslen = FT_MIN(dstsize, dstlen) + ft_strlen(src);
	if (dstsize > dstlen)
	{
		dst += dstlen;
		dstsize -= dstlen;
		while (*src && dstsize-- > 1)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (reslen);
}
