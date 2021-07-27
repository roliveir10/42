#include "libft.h"

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_islowercase(str[i]))
			return (0);
		i++;
	}
	return (1);
}
