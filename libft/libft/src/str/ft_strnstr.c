/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquincy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 18:39:19 by jquincy           #+#    #+#             */
/*   Updated: 2019/09/21 07:58:26 by jquincy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hs, const char *ndl, size_t len)
{
	char	*h;
	size_t	ndllen;
	size_t	i;
	size_t	j;

	i = 0;
	h = (char *)hs;
	if (!(ndllen = ft_strlen(ndl)))
		return (h);
	if (ft_strlen(hs) < ndllen || len < ndllen)
		return (NULL);
	while (h[i] && i <= len - ndllen)
	{
		j = 0;
		while (ndl[j] && ndl[j] == h[i + j])
			j++;
		if (j == ndllen)
			return (&h[i]);
		i++;
	}
	return (NULL);
}
