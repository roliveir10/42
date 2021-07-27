#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*udst;
	unsigned char	*usrc;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	udst = (unsigned char *)dst;
	usrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		udst[i] = usrc[i];
		i++;
	}
	return (dst);
}
