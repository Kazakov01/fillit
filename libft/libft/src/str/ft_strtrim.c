/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquincy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 04:26:26 by jquincy           #+#    #+#             */
/*   Updated: 2019/09/21 07:53:57 by jquincy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*res;
	size_t	st;
	size_t	fin;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	st = 0;
	fin = ft_strlen(s);
	while (ft_isblank(s[st]) || s[st] == '\n')
		st++;
	while (fin && (ft_isblank(s[fin - 1]) || s[fin - 1] == '\n'))
		fin--;
	if ((res = ft_strnew((fin > st) ? (fin - st) : 0)))
	{
		while (st < fin)
			res[i++] = s[st++];
		res[i] = '\0';
	}
	return (res);
}
