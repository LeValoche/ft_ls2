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

int			max_major(t_file *list)
{
	int		tmp;

	tmp = 0;
	while (list != NULL)
	{
		if (ft_intlen(major(list->device_id)) > tmp)
			tmp = ft_intlen(major(list->device_id));
		list = list->next;
	}
	return (tmp);
}

int			max_minor(t_file *list)
{
	int		tmp;

	tmp = 0;
	while (list != NULL)
	{
		if (ft_intlen(minor(list->device_id)) > tmp)
			tmp = ft_intlen(minor(list->device_id));
		list = list->next;
	}
	return (tmp);
}

t_file		*free_list(t_file *list)
{
	t_file	*tmp;

	if (list == NULL)
		return (NULL);
	tmp = list->next;
	free(list);
	tmp = free_list(tmp);
	return (tmp);
}
