/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmottal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 20:31:34 by mmottal           #+#    #+#             */
/*   Updated: 2018/05/10 19:30:10 by mmottal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				innexistant(char *str)
{
	struct stat		s;

	if (lstat(str, &s) == -1)
	{
		ft_putstr("ft_ls: ");
		ft_putstr(str);
		ft_putstr(": No such file or directory\n");
		return (-1);
	}
	return (0);
}

char			*get_path(char *dossier, char *str)
{
	char	*path;
	int		size;

	size = ft_strlen(dossier) + ft_strlen(str) + 2;
	path = NULL;
	if (!str)
		return (dossier);
	if (!(path = malloc(sizeof(char) * size)))
		exit(-1);
	ft_strcpy(path, dossier);
	if (dossier[ft_strlen(dossier) - 1] != '/')
		ft_strcat(path, "/");
	ft_strcat(path, str);
	return (path);
}

static void		get_flag_erreur(char *str)
{
	int		i;

	i = 0;
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(str[i]);
	ft_putendl("\nusage: ft_ls [-Radglort] [file ...]");
	exit(-1);
}

int				get_flag(char *str, int *flag)
{
	int		i;

	i = 0;
	while (str[++i])
	{
		if (str[i] == 'R')
			*flag = *flag | FLAG_R;
		else if (str[i] == 'r')
			*flag = *flag | FLAG_PETIT_R;
		else if (str[i] == 't')
			*flag = *flag | FLAG_T;
		else if (str[i] == 'l')
			*flag = *flag | FLAG_L;
		else if (str[i] == 'a')
			*flag = *flag | FLAG_A;
		else if (str[i] == 'd')
			*flag = *flag | FLAG_D;
		else if (str[i] == 'g')
			*flag = *flag | FLAG_G;
		else if (str[i] == 'o')
			*flag = *flag | FLAG_O;
		else
			get_flag_erreur(str);
	}
	return (0);
}
