/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmottal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:30:13 by mmottal           #+#    #+#             */
/*   Updated: 2017/11/27 17:16:55 by mmottal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	int		i;
	int		negative;
	int		nombre;

	i = 0;
	negative = 1;
	nombre = 0;
	while (nptr[i] == '\n' || nptr[i] == '\f' || nptr[i] == ' ' ||
			nptr[i] == '\r' || nptr[i] == '\v' || nptr[i] == '\t')
		i++;
	if (nptr[i] == '-')
	{
		negative = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		nombre = nombre * 10;
		nombre += ((int)nptr[i] - 48);
		i++;
	}
	return (negative * nombre);
}
