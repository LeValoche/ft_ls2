/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <vcohere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 03:57:10 by vcohere           #+#    #+#             */
/*   Updated: 2014/11/25 03:57:11 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file		*ft_lstswitch(t_file *l1, t_file *l2)
{
	l1->next = l2->next;
	l2->next = l1;
	return (l2);
}

/*
t_file		*sort_r(t_list *file)
{

}
*/
t_file		*time_sort(t_file *file)
{
	if (file == NULL)
		return (NULL);
	if (file->next != NULL && file->last_modif < file->next->last_modif)
		file = ft_lstswitch(file, file->next);
	file->next = time_sort(file->next);
	if (file->next != NULL && file->last_modif < file->next->last_modif)
	{
		file = ft_lstswitch(file, file->next);
		file->next = time_sort(file->next);
	}
	return (file);
}

t_file		*rev_sort(t_file *file)
{
	if (file == NULL)
		return (NULL);
	if (file->next != NULL && file->count < file->next->count)
		file = ft_lstswitch(file, file->next);
	file->next = rev_sort(file->next);
	if (file->next != NULL && file->count < file->next->count)
	{
		file = ft_lstswitch(file, file->next);
		file->next = rev_sort(file->next);
	}
	return (file);
}

int			is_check(t_file *file)
{
	t_file	*tmp;

	tmp = file->next;
	while (tmp->next != NULL)
	{
		if (file->last_modif > tmp->last_modif)
			return (0);
		tmp = tmp->next;
		file = file->next;
	}
	return (1);
}
/*
t_file		*sort_ascii(t_list *file)
{

}
*/