/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmottal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:38:36 by mmottal           #+#    #+#             */
/*   Updated: 2017/11/27 16:56:31 by mmottal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		taille;
	char	tmp;

	taille = 0;
	i = 0;
	while (str[taille])
		taille++;
	while (i < taille / 2)
	{
		tmp = str[taille - (i + 1)];
		str[taille - (i + 1)] = str[i];
		str[i] = tmp;
		i++;
	}
	return (str);
}
