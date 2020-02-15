/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquincy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 05:40:28 by jquincy           #+#    #+#             */
/*   Updated: 2019/09/21 10:25:43 by jquincy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nlen(int n, int negat)
{
	int		nlen;

	nlen = 1;
	while ((n /= 10))
		nlen++;
	return (nlen + negat);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		nlen;
	int		negat;
	int		dig;

	negat = (n < 0) ? 1 : 0;
	nlen = ft_nlen(n, negat);
	if ((str = ft_strnew((size_t)nlen)))
	{
		str[nlen--] = '\0';
		while (nlen >= negat)
		{
			dig = n % 10;
			str[nlen--] = (char)(FT_ABS(dig) + '0');
			n /= 10;
		}
		if (negat)
			str[0] = '-';
	}
	return (str);
}
