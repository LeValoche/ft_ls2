/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <vcohere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 15:40:58 by vcohere           #+#    #+#             */
/*   Updated: 2014/11/23 19:33:03 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#define PW(x) getpwuid(x)->pw_name)
#define GR(x) getgruid(x)->gr_name)

t_file				*save_infos(char *name_file, t_file *first, char *path)
{
	t_stat			st;
	t_file			*tmp;
	t_file			*mover;

	tmp = (t_file *)malloc(sizeof(t_file));
	mover = first;
	if (lstat(path, &st) <= 0)
	{
		set_infos(name_file, tmp, st);
		if (getpwuid(st.st_uid) != NULL)
			tmp->user = ft_strdup(getpwuid(st.st_uid)->pw_name);
		else
			tmp->user = ft_strdup("");
		if (getgrgid(st.st_gid) != NULL)
			tmp->group = ft_strdup(getgrgid(st.st_gid)->gr_name);
		else
			tmp->group = ft_strdup("");
	}
	if (first == NULL)
		return (tmp);
	while (mover->next != NULL)
		mover = mover->next;
	mover->next = tmp;
	return (first);
}

int					ft_options(char *input)
{
	int				options;
	int				i;

	options = 0b00000;
	i = 0;
	while (input[++i] != '\0')
	{
		if (input[i] == 't')
			options = options | 0b00001;
		else if (input[i] == 'r')
			options = options | 0b00010;
		else if (input[i] == 'a')
			options = options | 0b00100;
		else if (input[i] == 'R')
			options = options | 0b01000;
		else if (input[i] == 'l')
			options = options | 0b10000;
		else
		{
			ft_putstrchar("ft_ls: illegal option -- ", input[i]);
			ft_putstr("\nusage: ls [-Ralrt] [file ...]\n");
			exit(1);
		}
	}
	return (options);
}

void				recursive(char *path, t_file *list, int options, int nb_dir)
{
	char			**all_dir;
	int				i;

	i = 0;
	if (!(all_dir = (char **)malloc(sizeof(char *) * nb_dir + 1)))
		exit(1);
	all_dir[nb_dir + 1] = '\0';
	while (list != NULL)
	{
		if (list->is_dir == 1)
		{
			all_dir[i] = ft_strdup(list->name);
			i++;
		}
		list = list->next;
	}
	i = -1;
	while (++i < nb_dir)
	{
		if (options & 0b00100 && all_dir[i][0] == '.')
			ft_putcss('\n', ft_strjoin(path, all_dir[i]), ":\n");
		else if (all_dir[i][0] != '.')
			ft_putcss('\n', ft_strjoin(path, all_dir[i]), ":\n");
		browse(ft_strjoin(path, slash(all_dir[i])), options);
	}
}

void				browse(char *path, int options)
{
	DIR				*ret;
	struct dirent	*file;
	t_file			*list;

	if ((ret = opendir(path)) == NULL)
	{
		ft_putstr("ls: ");
		perror(rem_slash(get_dir(path)));
		return ;
	}
	file = readdir(ret);
	if (!(list = (t_file *)malloc(sizeof(t_file))))
		exit(1);
	list = NULL;
	while (file)
	{
		list = save_infos(file->d_name, list, ft_strjoin(path, file->d_name));
		file = readdir(ret);
	}
	closedir(ret);
	sort_my_tab(list, options, path);
}

int					main(int argc, char **argv)
{
	int				i;
	int				options;
	char			*path;

	i = 0;
	options = 0b00000;
	path = NULL;
	while (++i < argc)
	{
		if (argv[i][0] == '-')
			options = options | ft_options(argv[i]);
		else
		{
			path = argv[i];
			browse(slash(path), options);
		}
	}
	if (!path)
		browse("./", options);
	return (0);
}
