/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmottal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 18:39:13 by mmottal           #+#    #+#             */
/*   Updated: 2017/11/28 14:48:21 by mmottal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(const char *s, char c)
{
	size_t	i;
	size_t	k;
	int		fi;
	int		la;
	char	**tab;

	tab = NULL;
	i = 0;
	k = 0;
	if (s && (tab = (char **)malloc(sizeof(*tab) * (ft_strlen(s) / 2 + 2))))
	{
		while (s[i])
		{
			while (s[i] && s[i] == c)
				i++;
			fi = i;
			while (s[i] && s[i] != c)
				i++;
			la = i;
			if (la > fi)
				tab[k++] = ft_strsub(s, fi, (la - fi));
		}
		tab[k] = NULL;
	}
	return (tab);
}
