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

char		*get_dir(char *str)
{
	int		len;
	int		i;

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
