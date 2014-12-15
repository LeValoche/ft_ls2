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

int		max_major(t_file *list)
{
	int	tmp;

	tmp = 0;
	while (list != NULL)
	{
		if (ft_intlen(list->size) > tmp)
			tmp = ft_intlen(list->size);
		list = list->next;
	}
	return (tmp);
}

int		max_minor(t_file *list)
{
	int	tmp;

	tmp = 0;
	while (list != NULL)
	{
		if (ft_intlen(list->size) > tmp)
			tmp = ft_intlen(list->size);
		list = list->next;
	}
	return (tmp);
}