/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <vcohere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 16:43:55 by vcohere           #+#    #+#             */
/*   Updated: 2014/11/10 16:43:59 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

static int			ft_count_words(char const *s, char c)
{
	int				i;
	int				count;

	i = 0;
	count = 0;
	while (s[++i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c)
				i++;
		}
	}
	return (count);
}

static size_t		ft_strlenc(const char *str, int c)
{
	size_t			len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	return (len);
}

char				**ft_strsplit(char const *str, int c)
{
	size_t			len;
	size_t			i;
	char			**tab;
	char			*str2;

	i = 0;
	len = ft_count_words(str, c);
	tab = (char **)malloc(sizeof(char *) * len + 1);
	str2 = (char *)str;
	while (*str2 == c)
		str2++;
	while (i < len)
	{
		tab[i] = ft_strndup(str2, ft_strlenc(str2, c));
		str2 += ft_strlenc(str2, c);
		while (*str2 == c)
			str2++;
		i++;
	}
	tab[i] = 0;
	return (tab);
}
