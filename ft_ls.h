/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <vcohere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 15:44:15 by vcohere           #+#    #+#             */
/*   Updated: 2014/11/23 19:11:01 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# define REAL_DIR(x) (ft_strcmp(x, "..") != 0 && ft_strcmp(x, ".") != 0)
# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"
# define COLOR_RESET "\x1b[0m"
# include <dirent.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <stdlib.h>
# include <grp.h>
# include <time.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/includes/libft.h"

typedef struct		s_file
{
	char			*rights;
	int				links;
	char			*user;
	char			*group;
	size_t			size;
	char			*name;
	long long		last_modif;
	time_t			creation;
	int				is_dir;
	int				count;
	int				blocks;
	dev_t			device_id;
	struct s_file	*next;
}					t_file;

typedef struct stat t_stat;

t_file				*save_infos(char *name_file, t_file *first, char *path);
int					ft_options(char *input);
void				browse(char *path, int options);
int					main(int argc, char **argv);
char				*rights(struct stat *st);
char				*slash(char *str);
void				recursive(char *path, t_file *list, int options, int nb_dir);
t_file				*print(t_file *list, int options, char *path);
t_file				*ft_lstswitch(t_file *l1, t_file *l2);
t_file				*time_sort(t_file *file);
t_file				*rev_sort(t_file *file);
t_file				*set_index(t_file *file);
char				*get_dir(char *str);
int					inv_dir(char *dir);
t_file				*print_l(t_file *list, int options, char *path);
void				print_everything(t_file *list, char *path);
void				print_date(char *str);
void				print_date2(char *str);
int					max_size(t_file *list, int options);
int					max_group(t_file *list, int options);
int					max_user(t_file *list, int options);
int					max_links(t_file *list, int options);
int					max_minor(t_file *list, int options);
int					max_major(t_file *list, int options);
void				print_spaces(int n);
t_file				*ascii_sort(t_file *file);
int					count_total(t_file *list, int invisible);
char				*rem_slash(char *str);
void				free_double_tab(char **tab);
int					find_majmin(t_file *list);
void				ft_putstrspace(char *str, int n);
void				set_global(t_file *list, int options);
void				ft_putstrchar(char *str, char c);
void				ft_putcss(char c, char *s1, char *s2);
void				sort_my_tab(t_file *list, int options, char *path);
int					count_dir(t_file *list);
char				*rights_two(char *result, int i, t_stat *st);
void				set_infos(char *name_file, t_file *tmp, t_stat st);
void				ft_putname(t_file *list);

#endif
