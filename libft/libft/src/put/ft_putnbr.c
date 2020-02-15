/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquincy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 00:28:16 by jquincy           #+#    #+#             */
/*   Updated: 2019/09/17 02:50:55 by jquincy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned numb;

	if (n < 0)
	{
		ft_putchar('-');
	}
	numb = (unsigned)FT_ABS(n);
	if (numb >= 10)
	{
		ft_putnbr(numb / 10);
		ft_putnbr(numb % 10);
	}
	else
	{
		ft_putchar(numb + '0');
	}
}
