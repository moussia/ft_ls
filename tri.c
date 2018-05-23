/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmottal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 15:10:45 by mmottal           #+#    #+#             */
/*   Updated: 2018/05/09 17:11:40 by mmottal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		tri(t_list **liste_entiere, int (*cmp)())
{
	t_list	*tmp;
	t_list	*ptr;
	char	*next;

	tmp = *liste_entiere;
	if (!(*liste_entiere))
		return ;
	while (tmp)
	{
		ptr = *liste_entiere;
		while (ptr->next)
		{
			if ((*cmp)(ptr->data, ptr->next->data) > 0)
			{
				next = ptr->data;
				ptr->data = ptr->next->data;
				ptr->next->data = next;
			}
			ptr = ptr->next;
		}
		tmp = tmp->next;
	}
}

int			tri_date(char *s1, char *s2)
{
	struct stat		stat1;
	struct stat		stat2;

	if ((stat(s1, &stat1) == -1) || (stat(s2, &stat2) == -1))
		return (-1);
	return (stat2.st_mtime - stat1.st_mtime);
}

void		ls_r(t_list **liste_entiere)
{
	t_list	*begin;
	t_list	*current;
	t_list	*next;

	begin = NULL;
	current = *liste_entiere;
	while (current != NULL)
	{
		next = current->next;
		current->next = begin;
		begin = current;
		current = next;
	}
	*liste_entiere = begin;
}

void		ls_t(t_list **liste_entiere)
{
	tri(liste_entiere, &tri_date);
}
