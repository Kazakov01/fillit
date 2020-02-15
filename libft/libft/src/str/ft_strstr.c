/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquincy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 18:35:05 by jquincy           #+#    #+#             */
/*   Updated: 2019/09/20 21:31:50 by jquincy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *hs, const char *ndl)
{
	int lenndl;
	int lenhs;
	int i;
	int j;

	i = 0;
	if (*ndl == '\0')
	{
		return ((char *)hs);
	}
	lenndl = ft_strlen(ndl);
	lenhs = ft_strlen(hs);
	while (i <= lenhs - lenndl)
	{
		j = 0;
		while (j < lenndl && hs[i + j] == ndl[j])
			j++;
		if (j == lenndl)
			return ((char*)(hs + i));
		i++;
	}
	return (NULL);
}
