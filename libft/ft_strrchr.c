/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmottal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 18:22:58 by mmottal           #+#    #+#             */
/*   Updated: 2017/11/29 18:22:59 by mmottal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*out;

	out = NULL;
	while (*s)
	{
		if (*s == (char)c)
			out = (char *)s;
		s++;
	}
	if ((char)c == '\0')
		return ((char*)s);
	return (out);
}
