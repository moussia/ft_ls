/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmottal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 15:11:03 by mmottal           #+#    #+#             */
/*   Updated: 2018/05/10 15:40:40 by mmottal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <dirent.h>
# include <time.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <limits.h>
# include <pwd.h>
# include <grp.h>
# include "libft/libft.h"
# define FLAG_R 1
# define FLAG_PETIT_R 2
# define FLAG_A 4
# define FLAG_O 8
# define FLAG_L 16
# define FLAG_D 32
# define FLAG_G 64
# define FLAG_T 128
# define BUFSIZE 100

typedef struct		s_list
{
	char			*data;
	struct s_list	*next;
}					t_list;

char				*get_file_name(char *str);
void				ls_total(char *str, t_list *liste_entiere);
void				fichier(char *str, t_list *liste_entiere, int flag);
char				*get_path(char *str, char *dossier);
void				ft_re(t_list **liste_entiere);
void				ls_r(t_list **liste_entiere);
void				swap_node(t_list **node1, t_list **node2);
void				tri(t_list **liste_entiere, int (*cmp)());
void				ls_t(t_list **liste_entiere);
int					ft_ls(char *str);
void				file_type(struct stat sb);
void				temps(time_t time);
void				afficher_droit(mode_t m);
void				ft_ls_l(char *str, int flag);
int					innexistant(char *str);
int					get_flag(char *str, int *flag);
t_list				*set_list();
void				my_show_list(t_list *liste_entiere);
void				my_ls(char *str, int flag);
void				ft_recursive(char *str, int flag);
t_list				*mettre_dans_la_list(t_list *premier, char *valeur);
void				ft_sort_file(t_list **liste_entiere, int flag);

#endif
