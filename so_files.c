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
			break;
		len--;
	}
	ft_putnbr(len);
	if (i == 2)
 		return (ft_strsub(str, len, ft_strlen(str) - len));
	else
		return (str);
}