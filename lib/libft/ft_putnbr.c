/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 11:19:38 by srabah            #+#    #+#             */
/*   Updated: 2017/04/11 11:19:50 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	unsigned int	u_nbr;

	u_nbr = n;
	if (n < 0)
	{
		ft_putchar('-');
		u_nbr = -n;
	}
	if (u_nbr / 10)
		ft_putnbr(u_nbr / 10);
	ft_putchar(u_nbr % 10 + '0');
}
