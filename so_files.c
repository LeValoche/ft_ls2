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

t_file			*print_l(t_file *list, int options, char *path)
{
	t_file		*first;

	set_global(list, options);
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

void			set_global(t_file *list, int options)
{
	g_size = max_size(list, options);
	g_links = max_links(list, options);
	g_user = max_user(list, options);
	g_group = max_group(list, options);
	g_major = max_major(list, options);
	g_minor = max_minor(list, options);
}

void			print_majmin(t_file *list)
{
	if (list->rights[0] == 'b' || list->rights[0] == 'c')
	{
		print_spaces(g_major - ft_intlen(major(list->device_id)) + 1);
		ft_putnbr(major(list->device_id));
		ft_putstrspace(", ", g_minor - ft_intlen(minor(list->device_id)) - 1);
		ft_putnbr(minor(list->device_id));
	}
	else
	{
		if (g_major + g_minor + 3 > g_size && find_majmin(list))
			print_spaces(g_major + g_minor + 3 - ft_intlen(list->size));
		else
			print_spaces(g_size - ft_intlen(list->size));
		ft_putnbr(list->size);
	}
	ft_putchar(' ');
}

void			print_everything(t_file *list, char *path)
{
	time_t		tloc;
	char		buf[1024];
	ssize_t		len;

	time(&tloc);
	len = 1024;
	ft_putstrspace(list->rights, g_links - ft_intlen(list->links) + 1);
	ft_putnbr(list->links);
	ft_putchar(' ');
	ft_putstrspace(list->user, g_user - ft_strlen(list->user) + 1);
	ft_putstrspace(list->group, g_group - ft_strlen(list->group));
	print_majmin(list);
	if (list->creation + 15778800 >= tloc && list->creation - 15778800 <= tloc)
		print_date(ctime(&(list->creation)));
	else
		print_date2(ctime(&(list->creation)));
	ft_putstr(" ");
	ft_putname(list);
	if ((len = readlink(ft_strjoin(path, list->name), buf, len)) > -1)
	{
		buf[len] = '\0';
		ft_putstr(" -> ");
		ft_putstr(buf);
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
