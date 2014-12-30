/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lilbit_more.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 23:54:39 by vcohere           #+#    #+#             */
/*   Updated: 2014/12/09 14:43:30 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			max_size(t_file *list, int options)
{
	int		tmp;

	tmp = 0;
	while (list != NULL)
	{
		if (ft_intlen(list->size) > tmp)
		{
			if (list->name[0] != '.')
				tmp = ft_intlen(list->size);
			else if (list->name[0] == '.' && options & 0b00100)
				tmp = ft_intlen(list->size);
		}
		list = list->next;
	}
	return (tmp);
}

int			max_links(t_file *list, int options)
{
	int		tmp;

	tmp = 0;
	while (list != NULL)
	{
		if (ft_intlen(list->links) > tmp)
		{
			if (list->name[0] != '.')
				tmp = ft_intlen(list->links);
			else if (list->name[0] == '.' && options & 0b00100)
				tmp = ft_intlen(list->links);
		}
		list = list->next;
	}
	return (tmp);
}

int			max_user(t_file *list, int options)
{
	int		tmp;

	tmp = 0;
	while (list != NULL)
	{
		if (ft_strlen(list->user) > (size_t)tmp)
		{
			if (list->name[0] != '.')
				tmp = ft_strlen(list->user);
			else if (list->name[0] == '.' && options & 0b00100)
				tmp = ft_strlen(list->user);
		}
		list = list->next;
	}
	return (tmp);
}

int			max_group(t_file *list, int options)
{
	int		tmp;

	tmp = 0;
	while (list != NULL)
	{
		if (ft_strlen(list->group) > (size_t)tmp)
		{
			if (list->name[0] != '.')
				tmp = ft_strlen(list->group);
			else if (list->name[0] == '.' && options & 0b00100)
				tmp = ft_strlen(list->group);
		}
		list = list->next;
	}
	return (tmp);
}

void		print_spaces(int n)
{
	int		i;

	i = -1;
	while (++i <= n)
		ft_putchar(' ');
}
