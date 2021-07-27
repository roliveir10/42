#include <string.h>
#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	len;
	char	*new;

	len = ft_min(n, ft_strlen(s1) + 1);
	new = (char *)ft_calloc(len, sizeof(char));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1, len);
	return (new);
}
