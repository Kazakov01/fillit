/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquincy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 05:42:43 by jquincy           #+#    #+#             */
/*   Updated: 2019/09/21 07:29:57 by jquincy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned long	res;
	unsigned long	bor;
	size_t			i;
	int				sign;

	res = 0;
	bor = (unsigned long)(FT_LONG_MAX / 10);
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	sign = (str[i] == '-') ? -1 : 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		if ((res > bor || (res == bor && (str[i] - '0') > 7))
				&& sign == 1)
			return (-1);
		else if ((res > bor || (res == bor && (str[i] - '0') > 8))
				&& sign == -1)
			return (0);
		res = res * 10 + (str[i++] - '0');
	}
	return ((int)(res * sign));
}
