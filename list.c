/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmottal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:55:14 by mmottal           #+#    #+#             */
/*   Updated: 2018/05/10 12:43:41 by mmottal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list			*mettre_dans_la_list(t_list *premier, char *valeur)
{
	t_list	*element;

	if (!(element = (t_list*)malloc(sizeof(t_list))))
		exit(0);
	if (!(element->data = ft_strdup(valeur)))
		exit(0);
	element->next = premier;
	return (element);
}

t_list			*set_list(char *path, int flag)
{
	t_list			*nom;
	struct dirent	*d;
	DIR				*dir;

	nom = NULL;
	d = NULL;
	if (!(dir = opendir(path)))
		return (0);
	while ((d = readdir(dir)))
	{
		if (flag & FLAG_A)
			nom = (mettre_dans_la_list(nom, get_path(path, d->d_name)));
		else
		{
			if (d->d_name[0] != '.')
				nom = (mettre_dans_la_list(nom, get_path(path, d->d_name)));
		}
	}
	closedir(dir);
	return (nom);
}

char			*get_file_name(char *str)
{
	int		i;
	int		tmp;

	tmp = -1;
	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] == '/')
			tmp = i;
		i++;
	}
	if (tmp != -1)
		return (&str[tmp + 1]);
	return (str);
}

void			my_show_list(t_list *liste_entiere)
{
	struct stat		sb;
	char			*buf;
	int				size;

	if (!(buf = malloc(sizeof(char) * BUFSIZE)))
		exit(-1);
	while (liste_entiere)
	{
		size = 0;
		if (lstat(liste_entiere->data, &sb) == -1)
			exit(-1);
		ft_putstr(get_file_name(liste_entiere->data));
		if (S_ISLNK(sb.st_mode))
		{
			size = readlink(liste_entiere->data, buf, BUFSIZE);
			buf[size] = '\0';
			ft_putstr(" -> ");
			ft_putstr(buf);
		}
		ft_putstr("\n");
		liste_entiere = liste_entiere->next;
	}
}
