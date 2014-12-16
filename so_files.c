/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 21:31:38 by vcohere           #+#    #+#             */
/*   Updated: 2014/12/08 21:31:44 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				g_size;
int				g_links;
int				g_user;
int				g_group;
int				g_major;
int				g_minor;

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

int				inv_dir(char *dir)
{
	int			i;

	i = ft_strlen(dir);
	if (dir[0] == '.' && i == 2)
		return (1);
	else if (dir[0] == '.' && dir[1] == '.' && i == 3)
		return (1);
	else if (dir[0] != '.')
		return (1);
	return (0);
}

t_file			*print_l(t_file *list, int options, char *path)
{
	t_file		*first;

	g_size = max_size(list);
	g_links = max_links(list);
	g_user = max_user(list);
	g_group = max_group(list);
	g_major = max_major(list);
	g_minor = max_minor(list);
	first = list;
	ft_putstr("total ");
	ft_putnbr(count_total(list, options & 0b00100));
	ft_putendl("");
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
			print_everything(list, path);
		else if (list->name[0] != '.' && inv_dir(get_dir(path)))
			print_everything(list, path);
		list = list->next;
	}
	return (first);
}

void			print_everything(t_file *list, char *path)
{
	time_t		tloc;
	char		buf[1024];
	ssize_t		len;

	time(&tloc);
	ft_putstr(list->rights);
	print_spaces(g_links - ft_intlen(list->links));
	ft_putnbr(list->links);
	ft_putchar(' ');
	ft_putstr(list->user);
	print_spaces(g_user - ft_strlen(list->user));
	ft_putchar(' ');
	ft_putstr(list->group);
	print_spaces(g_group - ft_strlen(list->group));
	if (ft_strchr("bc", list->rights[0]))
	{
		print_spaces(g_major - ft_intlen(major(list->device_id)));
		ft_putnbr(major(list->device_id));
		ft_putstr(", ");
		print_spaces(g_minor - ft_intlen(minor(list->device_id)));
		ft_putnbr(minor(list->device_id));
	}
	else
	{
		if (g_major + g_minor + 1 > g_size)
		{
			ft_putendl("yolo");
			print_spaces(g_major + g_minor - ft_intlen(list->size));
		}
		else
			print_spaces(g_size - ft_intlen(list->size));
		ft_putnbr(list->size);
	}
	ft_putstr(" ");
	if (list->creation + 15778800 > tloc && list->creation < tloc)
		print_date(ctime(&(list->creation)));
	else
		print_date2(ctime(&(list->creation)));
	ft_putstr(" ");
	ft_putstr(list->name);
	if (list->rights[0] == 'l')
	{
		len = readlink(ft_strjoin(path, list->name), buf, len);
		buf[len] = '\0';
		ft_putstr(ft_strjoin(" -> ", buf));
	}
	ft_putendl("");
}

void			print_date(char *str)
{
	int			i;

	i = 4;
	while (str[i + 9] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}
