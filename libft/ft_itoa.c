/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmottal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 11:05:21 by mmottal           #+#    #+#             */
/*   Updated: 2017/11/27 15:12:44 by mmottal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(int n)
{
	int		i;

	i = 2;
	if (n < 0)
	{
		i++;
		n = n * -1;
	}
	while (n > 9)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	long	i;
	int		longueur;
	char	*str;

	i = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	longueur = count(n);
	if (!(str = (char *)malloc(sizeof(char) * longueur)))
		return (NULL);
	if (n < 0)
		n = n * (-1);
	str[--longueur] = '\0';
	while ((--longueur) >= 0)
	{
		str[longueur] = n % 10 + '0';
		n = n / 10;
	}
	if (i < 0)
		*str = '-';
	return (str);
}
