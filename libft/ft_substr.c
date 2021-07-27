#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	size_t	len_new;
	char	*new;

	len_s = ft_strlen(s);
	if (start >= len_s)
		return ((char *)ft_calloc(1, sizeof(char)));
	if (start + len >= len_s)
		len_new = len_s - start;
	else
		len_new = len;
	new = (char *)malloc(sizeof(char) * (len_new + 1));
	if (new)
		ft_strlcpy(new, &s[start], len_new + 1);
	return (new);
}
