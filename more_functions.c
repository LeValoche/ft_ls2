/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <vcohere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 15:43:08 by vcohere           #+#    #+#             */
/*   Updated: 2014/11/23 19:33:05 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*rights(t_stat *st)
{
	char	result[11];
	int		i;

	result[10] = '\0';
	i = -1;
	if (S_ISDIR(st->st_mode))
		result[++i] = 'd';
	else if (S_ISBLK(st->st_mode))
		result[++i] = 'b';
	else if (S_ISCHR(st->st_mode))
		result[++i] = 'c';
	else if (S_ISLNK(st->st_mode))
		result[++i] = 'l';
	else if (S_ISFIFO(st->st_mode))
		result[++i] = 'p';
	else if (S_ISSOCK(st->st_mode))
		result[++i] = 's';
	else
		result[++i] = '-';
	return (ft_strdup(rights_two(result, i, st)));
}

char		*slash(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		;
	if (str[i - 1] != '/')
		str = ft_strjoin(str, "/");
	return (str);
}

t_file		*print(t_file *list, int options, char *path)
{
	t_file	*first;

	first = list;
	while (list != NULL)
	{
		if (list->user[0] == '\0' || list->group[0] == '\0')
		{
			if (list->name[0] != '.' && options & 0b00100)
			{
				ft_putstr("ft_ls: ");
				ft_putstr(list->name);
				ft_putendl(": Permision denied");
			}
		}
		else if (options & 0b00100)
			ft_putendl(list->name);
		else if (list->name[0] != '.' && inv_dir(get_dir(path)))
			ft_putendl(list->name);
		list = list->next;
	}
	return (first);
}

int			count_dir(t_file *list)
{
	int		i;

	i = 0;
	while (list != NULL)
	{
		if (list->is_dir)
			i++;
		list = list->next;
	}
	return (i);
}

t_file		*set_index(t_file *file)
{
	t_file	*first;
	int		i;

	first = file;
	i = 0;
	while (file != NULL)
	{
		file->count = i;
		i++;
		file = file->next;
	}
	return (first);
}
