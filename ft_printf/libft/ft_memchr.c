#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*us;
	size_t			i;

	i = 0;
	us = (unsigned char *)s;
	while (i < n)
	{
		if (us[i] == (unsigned char)c)
			return ((void *)&us[i]);
		i++;
	}
	return (NULL);
}
