/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquincy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 04:13:14 by jquincy           #+#    #+#             */
/*   Updated: 2019/09/23 05:02:44 by jquincy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*str1;
	char	*str2;
	size_t	i;

	str1 = dst;
	str2 = (char *)src;
	i = -1;
	if (str1 == 0 && str2 == 0)
		return (NULL);
	while (++i < n)
		*(str1 + i) = *(str2 + i);
	return (dst);
}
