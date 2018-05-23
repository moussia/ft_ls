/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmottal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 13:47:19 by mmottal           #+#    #+#             */
/*   Updated: 2018/05/10 19:39:27 by mmottal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		fichier(char *str, t_list *liste_entiere, int flag)
{
	t_list		*next;

	if (!(liste_entiere))
		return ;
	ls_total(str, liste_entiere);
	while (liste_entiere)
	{
		ft_ls_l(liste_entiere->data, flag);
		liste_entiere = liste_entiere->next;
	}
}

void		ft_taille(struct stat sb, char *name, char *str)
{
	ft_putnbr(sb.st_size);
	ft_putstr("\t");
	temps(sb.st_mtime);
	name = get_file_name(str);
	ft_putstr(name);
}

void		ft_link(char *str, char *buf)
{
	int	size;

	size = 0;
	size = readlink(str, buf, BUFSIZE);
	buf[size] = '\0';
	ft_putstr(" -> ");
	ft_putstr(buf);
}

void		ft_bis(int flag, struct stat sb, char *str)
{
	int		size;
	char	*name;
	char	*buf;

	buf = 0;
	if (!(buf = malloc(sizeof(char) * BUFSIZE)))
		exit(-1);
	if (!(flag & FLAG_G) && ((flag & FLAG_O) || (flag & FLAG_L)))
	{
		ft_putstr(getpwuid(sb.st_uid)->pw_name);
		ft_putstr("\t");
	}
	if (!(flag & FLAG_O) && ((flag & FLAG_G) || (flag & FLAG_L)))
	{
		ft_putstr(getgrgid(sb.st_gid)->gr_name);
		ft_putstr("\t");
	}
	ft_taille(sb, name, str);
	if (S_ISLNK(sb.st_mode))
		ft_link(str, buf);
	ft_putstr("\n");
	if (buf)
		free(buf);
}

void		ft_ls_l(char *str, int flag)
{
	struct stat		sb;

	if (lstat(str, &sb) == -1 || (!str))
		return ;
	file_type(sb);
	afficher_droit(sb.st_mode);
	ft_putstr("\t");
	ft_putnbr(sb.st_nlink);
	ft_putstr("\t");
	ft_bis(flag, sb, str);
}
