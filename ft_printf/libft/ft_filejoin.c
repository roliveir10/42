#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_filejoin(char const *s1, char const *s2, int n1, int n2)
{
	size_t	len_total;
	char	*new;
	int		i;

	len_total = n1 + n2;
	new = (char *)malloc(sizeof(char) * (len_total + 1));
	i = 0;
	if (new)
	{
		while (i < n1)
		{
			new[i] = s1[i];
			i++;
		}
		i = 0;
		while (i < n2)
		{
			new[n1 + i] = s2[i];
			i++;
		}
		new[len_total] = 0;
	}
	return (new);
}
