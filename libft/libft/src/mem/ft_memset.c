/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquincy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 21:06:17 by jquincy           #+#    #+#             */
/*   Updated: 2019/09/19 05:30:24 by jquincy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *str;
	unsigned char i;

	str = (unsigned char *)b;
	i = (unsigned char)c;
	while (len--)
	{
		*str++ = i;
	}
	return (b);
}
