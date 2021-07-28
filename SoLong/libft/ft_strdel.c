#include <stdlib.h>

char	*ft_strdel(char **str)
{
	if (str)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}
