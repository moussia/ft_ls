/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_re.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmottal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 11:10:12 by mmottal           #+#    #+#             */
/*   Updated: 2018/05/10 18:12:43 by mmottal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ls_d(char *str, int flag)
{
	if (flag & FLAG_L)
		ft_ls_l(str, flag);
	else
		ft_putendl(str);
}

void		ft_recursive_two(char *str, int flag)
{
	struct stat		sb;

	if (lstat(str, &sb) == -1)
		return ;
	if (flag & FLAG_D || !(S_ISDIR(sb.st_mode)))
	{
		ls_d(str, flag);
		return ;
	}
	ft_putstr(str);
	ft_putstr(":\n");
	my_ls(str, flag);
	ft_putstr("\n");
}

void		ft_recursive(char *str, int flag)
{
	struct dirent	*d;
	DIR				*dir;
	struct stat		sb;
	char			*name;

	ft_recursive_two(str, flag);
	if (!(dir = opendir(str)))
		return ;
	while ((d = readdir(dir)))
	{
		if (!str || !(name = get_path(str, d->d_name)) ||
				(lstat(name, &sb) == -1))
			return ;
		if (S_ISDIR(sb.st_mode))
		{
			if ((flag & FLAG_A) && ft_strcmp(d->d_name, "..") != 0
					&& ft_strcmp(d->d_name, ".") != 0)
				ft_recursive(name, flag);
			else if (d->d_name[0] != '.')
				ft_recursive(name, flag);
		}
	}
	closedir(dir);
}

void		ft_sort_file(t_list **liste_entiere, int flag)
{
	tri(liste_entiere, &ft_strcmp);
	if (flag & FLAG_T)
		ls_t(liste_entiere);
	if (flag & FLAG_PETIT_R)
		ls_r(liste_entiere);
	return ;
}

void		my_ls(char *str, int flag)
{
	struct stat		s;
	t_list			*liste_entiere;

	if ((innexistant(str)) == -1)
		return ;
	if (lstat(str, &s) == -1)
		return ;
	liste_entiere = NULL;
	if (flag & FLAG_D || !(S_ISDIR(s.st_mode)))
	{
		ls_d(str, flag);
		return ;
	}
	liste_entiere = set_list(str, flag);
	ft_sort_file(&liste_entiere, flag);
	if ((flag & FLAG_L) || (flag & FLAG_O) || (flag & FLAG_G))
		fichier(str, liste_entiere, flag);
	else
		my_show_list(liste_entiere);
}
