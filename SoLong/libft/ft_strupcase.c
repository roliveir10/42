#include "libft.h"

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_islowercase(str[i]))
			str[i] -= 32;
		i++;
	}
	return (str);
}
