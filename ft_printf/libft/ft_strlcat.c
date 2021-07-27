#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	dlen;
	size_t	dsrc;
	size_t	i;

	dlen = ft_strlen(dst);
	dsrc = ft_strlen(src);
	if (n <= dlen)
		return (dsrc + n);
	i = 0;
	while (src[i] && i < n - dlen - 1)
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = 0;
	return (dlen + dsrc);
}
