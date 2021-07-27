#include <string.h>
#include "libft.h"

char	*strstr(const char *haystack, const char *needle)
{
	size_t	needle_len;
	size_t	i;

	i = 0;
	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *)haystack);
	while (haystack[i])
	{
		if (!ft_strncmp(&haystack[i], needle, needle_len))
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
