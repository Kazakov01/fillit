/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquincy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 20:29:00 by jquincy           #+#    #+#             */
/*   Updated: 2019/09/21 07:27:42 by jquincy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *str;
	char sm;

	str = (char *)s + ft_strlen(s);
	sm = (char)c;
	while (str >= s)
	{
		if (*str == sm)
			return (str);
		str--;
	}
	return (NULL);
}
