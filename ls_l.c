/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_l.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmottal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 11:57:28 by mmottal           #+#    #+#             */
/*   Updated: 2018/05/10 19:02:36 by mmottal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ls_total(char *str, t_list *liste_entiere)
{
	int				total;
	struct stat		sb;

	if (lstat(str, &sb) == -1)
		return ;
	total = 0;
	while (liste_entiere)
	{
		lstat(liste_entiere->data, &sb);
		total = total + (int)sb.st_blocks;
		liste_entiere = liste_entiere->next;
	}
	ft_putstr("total ");
	ft_putnbr(total);
	ft_putstr("\n");
}

void		file_type(struct stat sb)
{
	if (S_ISDIR(sb.st_mode))
		ft_putchar('d');
	else if (S_ISLNK(sb.st_mode))
		ft_putchar('l');
	else if (S_ISCHR(sb.st_mode))
		ft_putchar('c');
	else if (S_ISSOCK(sb.st_mode))
		ft_putchar('s');
	else if (S_ISBLK(sb.st_mode))
		ft_putchar('b');
	else if (S_ISFIFO(sb.st_mode))
		ft_putchar('p');
	else if (S_ISREG(sb.st_mode))
		ft_putchar('-');
}

void		afficher_droit(mode_t mode)
{
	ft_putstr((S_IRUSR & mode) ? "r" : "-");
	ft_putstr((S_IWUSR & mode) ? "w" : "-");
	ft_putstr((S_IXUSR & mode) ? "x" : "-");
	ft_putstr((S_IRWXG & mode) ? "r" : "-");
	ft_putstr((S_IWGRP & mode) ? "w" : "-");
	ft_putstr((S_IXGRP & mode) ? "x" : "-");
	ft_putstr((S_IROTH & mode) ? "r" : "-");
	ft_putstr((S_IWOTH & mode) ? "w" : "-");
	ft_putstr((S_IXOTH & mode) ? "x" : "-");
}

void		temps(time_t time)
{
	char			*temps;
	int				i;

	temps = ctime(&time);
	i = 4;
	while (i < 7)
	{
		ft_putchar(temps[i]);
		i++;
	}
	ft_putchar(' ');
	ft_putchar(temps[8]);
	if (temps[9] != ' ')
		ft_putchar(temps[9]);
	ft_putstr(" ");
	i = 11;
	while (i < 16)
	{
		ft_putchar(temps[i]);
		i++;
	}
	ft_putchar(' ');
}
