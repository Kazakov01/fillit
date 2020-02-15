/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquincy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 02:44:54 by jquincy           #+#    #+#             */
/*   Updated: 2019/09/21 12:53:27 by jquincy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned numb;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
	}
	numb = (unsigned)FT_ABS(n);
	if (numb >= 10)
	{
		ft_putnbr_fd(numb / 10, fd);
		ft_putnbr_fd(numb % 10, fd);
	}
	else
	{
		ft_putchar_fd(numb + '0', fd);
	}
}
