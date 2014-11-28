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
/*
t_file		*sort_r(t_list *file)
{

}
*/
t_file		*sort_t(t_file *file)
{
	int		end;
	t_file	*ptr1;
	t_file	*ptr2;
	t_file	*ptr3;

	end = 0;
	ptr1 = file;
	ptr2 = ptr1->next;
	ptr3 = ptr2->next;
	while (!end)
	{
		end = 0;
		end += ex_1to2(file, ptr1, ptr2, ptr3);
		end += ex_2to3(ptr1, ptr2, ptr3);
		if (ptr3->next == NULL)
		{
			ptr1 = file;
			ptr2 = ptr1->next;
			ptr3 = ptr2->next;
		}
		else
		{
			ptr1 = ptr2;
			ptr2 = ptr3;
			ptr3 = ptr3->next;
		}
	}
	return (file);
}
/*
t_file		*sort_ascii(t_list *file)
{

}
*/
int			ex_2to3(t_file *ptr1, t_file *ptr2, t_file *ptr3)
{
	if (ptr2->last_modif > ptr3->last_modif)
	{
		ptr1->next = ptr3;
		ptr2->next = ptr3->next;
		ptr3->next = ptr2;
		return (1);
	}	
	return (0);
}

int			ex_1to2(t_file *file, t_file *ptr1, t_file *ptr2, t_file *ptr3)
{
	if (ptr1 == file && ptr1->last_modif > ptr2->last_modif)
	{
		file = ptr2;
		ptr1->next = ptr3;
		ptr2->next = ptr1;
		return (1);
	}
	return (0);
}