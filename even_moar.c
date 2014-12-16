/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   even_moar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 16:15:22 by vcohere           #+#    #+#             */
/*   Updated: 2014/12/09 16:15:24 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			print_date2(char *str)
{
	int			i;
	int			j;

	i = 4;
	j = ft_strlen(str) - 5;
	while (str[i + 14] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	i = ft_strlen(str) - 6;
	while (str[i] != '\n')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int				count_total(t_file *list, int a)
{
	int			result;

	result = 0;
	while (list != NULL)
	{
		if (a)
			result += list->blocks;
		else if (list->name[0] != '.')
			result += list->blocks;
		list = list->next;
	}
	return (result);
}

char			*rem_slash(char *str)
{
	int			len;

	len = ft_strlen(str);
	str[len - 1] = '\0';
	return (str);
}