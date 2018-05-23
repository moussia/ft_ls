/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmottal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 13:26:53 by mmottal           #+#    #+#             */
/*   Updated: 2017/11/27 15:13:56 by mmottal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		start;
	int		end;
	char	len;

	start = 0;
	end = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	while (s[len - 1] == ' ' || s[len - 1] == '\t' || s[len - 1] == '\n')
		len--;
	while (s[start] == '\n' || s[start] == ' ' || s[start] == '\t')
	{
		start++;
		len--;
	}
	if (len < 0)
		len = 0;
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (end < len)
		str[end++] = s[start++];
	str[end] = '\0';
	return (str);
}
