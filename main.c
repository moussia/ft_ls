/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmottal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 12:43:24 by mmottal           #+#    #+#             */
/*   Updated: 2018/05/10 19:32:09 by mmottal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_main(int flag)
{
	if (flag & FLAG_R)
		ft_recursive(".", flag);
	else
		my_ls(".", flag);
	return (0);
}

void	ft_b(t_list *list, int flag)
{
	while (list)
	{
		ft_sort_file(&list, flag);
		if (flag & FLAG_R)
			ft_recursive(list->data, flag);
		else
			my_ls(list->data, flag);
		list = list->next;
	}
}

int		main(int argc, char **argv)
{
	int		i;
	int		flag;
	t_list	*list;

	flag = 0;
	i = 1;
	while (i < argc && argv[i][0] == '-' && ft_strlen(argv[i]) > 1)
	{
		get_flag(argv[i], &flag);
		i++;
	}
	if (i == argc)
		ft_main(flag);
	while (i < argc)
	{
		list = mettre_dans_la_list(list, argv[i]);
		i++;
	}
	ft_b(list, flag);
	return (0);
}
