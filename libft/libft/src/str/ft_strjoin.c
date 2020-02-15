/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquincy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:39:48 by jquincy           #+#    #+#             */
/*   Updated: 2019/09/20 21:45:08 by jquincy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	lens1;
	size_t	lens2;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	str = (char *)malloc((lens1 + lens2 + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < lens1)
	{
		str[i] = s1[i];
		i++;
	}
	while (i - lens1 < lens2)
	{
		str[i] = s2[i - lens1];
		i++;
	}
	str[i] = '\0';
	return (str);
}
