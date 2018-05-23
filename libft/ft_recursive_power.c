/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmottal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 19:22:47 by mmottal           #+#    #+#             */
/*   Updated: 2017/11/23 19:24:41 by mmottal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_recursive_power(int nb, int power)
{
	if (power == 1)
		return (nb);
	if (power >= 2)
		return (nb * ft_recursive_power(nb, power - 1));
	if (power == 0)
		return (1);
	return (0);
}
