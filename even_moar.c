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

	i = 4;
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

void			set_infos(char *name_file, t_file *tmp, t_stat st)
{
	tmp->rights = rights(&st);
	tmp->name = ft_strdup(name_file);
	tmp->size = st.st_size;
	tmp->links = st.st_nlink;
	tmp->last_modif = (long long)st.st_mtime;
	tmp->creation = st.st_mtime;
	tmp->is_dir = (tmp->rights[0] == 'd' && REAL_DIR(tmp->name));
	tmp->blocks = st.st_blocks;
	tmp->device_id = st.st_rdev;
	tmp->next = NULL;
}

void			ft_putname(t_file *list)
{
	if (list->rights[0] == 'd')
		ft_putstr(GREEN);
	else if (list->rights[0] == 'l')
		ft_putstr(RED);
	else if (list->rights[0] == 'c')
		ft_putstr(BLUE);
	else if (list->rights[0] == 'b')
		ft_putstr(MAGENTA);
	ft_putstr(list->name);
	ft_putstr(COLOR_RESET);
}
