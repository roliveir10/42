#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*udst;
	unsigned char	*usrc;

	udst = (unsigned char *)dst;
	usrc = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (udst < usrc)
		return (ft_memcpy(dst, src, len));
	while (len)
	{
		udst[len - 1] = usrc[len - 1];
		len--;
	}
	return (dst);
}
