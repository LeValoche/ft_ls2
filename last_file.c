/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 00:46:35 by vcohere           #+#    #+#             */
/*   Updated: 2014/12/27 00:46:36 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			*get_dir(char *str)
{
	int			len;
	int			i;

	len = ft_strlen(str) - 1;
	i = 0;
	while (len > 0)
	{
		if (str[len] == '/')
			i++;
		if (i == 2)
		{
			len++;
			break ;
		}
		len--;
	}
	if (i == 2)
		return (ft_strsub(str, len, ft_strlen(str) - len));
	else
		return (str);
}

void			ft_putstrchar(char *str, char c)
{
	ft_putstr(str);
	ft_putchar(c);
}

void			ft_putcss(char c, char *s1, char *s2)
{
	ft_putchar(c);
	ft_putstr(s1);
	ft_putstr(s2);
}

void			sort_my_tab(t_file *list, int options, char *path)
{
	list = ascii_sort(list);
	if (options & 0b00001)
		list = time_sort(list);
	list = set_index(list);
	if (options & 0b00010)
		list = rev_sort(list);
	if (list != NULL && options & 0b10000)
		list = print_l(list, options, path);
	else if (list != NULL)
		list = print(list, options, path);
	if (options & 0b01000)
		recursive(path, list, options, count_dir(list));
}

char			*rights_two(char *result, int i, t_stat *st)
{
	result[++i] = (st->st_mode & S_IRUSR) ? 'r' : '-';
	result[++i] = (st->st_mode & S_IWUSR) ? 'w' : '-';
	result[++i] = (st->st_mode & S_IXUSR) ? 'x' : '-';
	result[++i] = (st->st_mode & S_IRGRP) ? 'r' : '-';
	result[++i] = (st->st_mode & S_IWGRP) ? 'w' : '-';
	result[++i] = (st->st_mode & S_IXGRP) ? 'x' : '-';
	result[++i] = (st->st_mode & S_IROTH) ? 'r' : '-';
	result[++i] = (st->st_mode & S_IWOTH) ? 'w' : '-';
	result[++i] = (st->st_mode & S_IXOTH) ? 'x' : '-';
	return (result);
}
