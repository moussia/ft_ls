/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmottal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:02:34 by mmottal           #+#    #+#             */
/*   Updated: 2017/11/27 18:42:12 by mmottal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	puissance(int p)
{
	int		a;

	a = 1;
	while (p != 1)
	{
		a = a * 10;
		p--;
	}
	return (a);
}

static int	fonction_nb(int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void		ft_putnbr(int nb)
{
	long	nombre;
	int		c;
	int		nbc;

	nombre = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		nombre = -nombre;
	}
	nbc = fonction_nb(nb);
	while (nbc != 0)
	{
		c = nombre / puissance(nbc);
		ft_putchar(c + '0');
		nombre = nombre - (c * puissance(nbc));
		nbc--;
	}
}
