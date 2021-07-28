#include <string.h>
#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	size_t	i;
	int		destlen;

	i = 0;
	destlen = ft_strlen(dest);
	while (i < nb && src[i])
	{
		dest[destlen] = src[i];
		destlen++;
		i++;
	}
	dest[destlen] = 0;
	return (dest);
}
