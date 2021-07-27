#include "libft.h"

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isuppercase(str[i]))
			str[i] += 32;
		i++;
	}
	return (str);
}
