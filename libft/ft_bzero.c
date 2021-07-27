#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*s2;

	s2 = (char *)s;
	i = 0;
	while (i < n)
	{
		s2[i] = 0;
		i++;
	}
}
