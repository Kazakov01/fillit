/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquincy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 20:34:02 by jquincy           #+#    #+#             */
/*   Updated: 2019/09/20 21:33:31 by jquincy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t lendest;

	i = 0;
	lendest = ft_strlen(dest);
	while (src[i] != '\0' && i < n)
	{
		dest[lendest + i] = src[i];
		i++;
	}
	dest[lendest + i] = '\0';
	return (dest);
}
