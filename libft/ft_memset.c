#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	char			*string;

	i = 0;
	string = (char *)b;
	while (i < len)
	{
		string[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
