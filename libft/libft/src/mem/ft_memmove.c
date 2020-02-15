/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquincy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 03:34:34 by jquincy           #+#    #+#             */
/*   Updated: 2019/09/23 04:30:17 by jquincy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*src1;
	char	*dst1;
	size_t	i;

	i = 0;
	src1 = (char *)src;
	dst1 = (char *)dst;
	if (src1 == 0 && dst1 == 0)
		return (NULL);
	if (src1 < dst1)
		while (len)
		{
			len--;
			*(dst1 + len) = *(src1 + len);
		}
	else
		while (i < len)
		{
			*(dst1 + i) = *(src1 + i);
			i++;
		}
	return (dst);
}
