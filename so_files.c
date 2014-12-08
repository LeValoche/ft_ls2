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
	t_file	*first;

	first = list;
	while (list != NULL)
	{
		if (options & 0b00100)
			print_everything(list);
		else if (list->name[0] != '.' && inv_dir(get_dir(path)))
			print_everything(list);
		list = list->next;
	}
	return (first);
}

void			print_everything(t_file *list)
{
	ft_putstr(list->rights);
	ft_putstr(" ");
	ft_putnbr(list->links);
	ft_putstr(" ");
	ft_putstr(list->user);
	ft_putstr(" ");
	ft_putstr(list->group);
	ft_putstr(" ");
	ft_putnbr(list->size);
	ft_putstr(" ");
	print_date(ctime(&(list->creation)));
	ft_putstr(" ");
	ft_putendl(list->name); 
}

void		print_date(char *str)
{
	int		i;

	i = 4;
	while (str[i + 9] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}