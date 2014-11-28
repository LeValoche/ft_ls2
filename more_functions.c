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

char		*rights(struct stat *st)
{
	char	result[11];
	int		i;

	result[10] = '\0';
	i = -1;
	result[++i] = (S_ISDIR(st->st_mode)) ? 'd' : '-';
	result[++i] = (st->st_mode & S_IRUSR) ? 'r' : '-';
	result[++i] = (st->st_mode & S_IWUSR) ? 'w' : '-';
	result[++i] = (st->st_mode & S_IXUSR) ? 'x' : '-';
	result[++i] = (st->st_mode & S_IRGRP) ? 'r' : '-';
	result[++i] = (st->st_mode & S_IWGRP) ? 'w' : '-';
	result[++i] = (st->st_mode & S_IXGRP) ? 'x' : '-';
	result[++i] = (st->st_mode & S_IROTH) ? 'r' : '-';
	result[++i] = (st->st_mode & S_IWOTH) ? 'w' : '-';
	result[++i] = (st->st_mode & S_IXOTH) ? 'x' : '-';
	return (ft_strdup(result));
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

void		print(t_file *list, int options, char *path)
{
	//list = sort_t(list);
	while (list != NULL)
	{
		if (options & 0b00100 && list->name[0] == '.')
			ft_putendl(list->name);
		else if (list->name[0] != '.')
		{
			ft_putendl(list->name);
			ft_putnbr(list->last_modif);
			ft_putchar('\n');
		}
		list = list->next;
	}
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