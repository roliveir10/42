#include "libft.h"

char	*ft_strrev(char *str)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		ft_swap_char(&str[i], &str[len - i]);
		i++;
	}
	return (str);
}
