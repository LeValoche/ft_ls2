/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 11:22:37 by vcohere           #+#    #+#             */
/*   Updated: 2014/12/15 11:22:39 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			max_major(t_file *list, int options)
{
	int		tmp;

	tmp = 0;
	while (list != NULL)
	{
		if (ft_intlen(major(list->device_id)) > tmp)
		{
			if (list->name[0] != '.')
				tmp = ft_intlen(major(list->device_id));
			else if (list->name[0] == '.' && options & 0b00100)
				tmp = ft_intlen(major(list->device_id));
		}
		list = list->next;
	}
	return (tmp);
}

int			max_minor(t_file *list, int options)
{
	int		tmp;

	tmp = 0;
	while (list != NULL)
	{
		if (ft_intlen(minor(list->device_id)) > tmp)
		{
			if (list->name[0] != '.')
				tmp = ft_intlen(minor(list->device_id));
			else if (list->name[0] == '.' && options & 0b00100)
				tmp = ft_intlen(minor(list->device_id));
		}
		list = list->next;
	}
	return (tmp);
}

void		ft_putstrspace(char *str, int n)
{
	ft_putstr(str);
	print_spaces(n);
}

int			find_majmin(t_file *list)
{
	while (list != NULL)
	{
		if (list->rights[0] == 'b' || list->rights[0] == 'c')
			return (1);
		list = list->next;
	}
	return (0);
}

int			inv_dir(char *dir)
{
	int		i;

	i = ft_strlen(dir);
	if (dir[0] == '.' && i == 2)
		return (1);
	else if (dir[0] == '.' && dir[1] == '.' && i == 3)
		return (1);
	else if (dir[0] != '.')
		return (1);
	return (0);
}
