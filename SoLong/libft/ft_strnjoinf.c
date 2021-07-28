#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strnjoinf(char **s1, char const *s2, int n1, int n2)
{
	size_t	len_total;
	char	*new;
	int		i;

	len_total = n1 + n2;
	new = (char *)malloc(sizeof(char) * (len_total + 1));
	i = 0;
	if (!new)
		return (NULL);
	ft_strlcpy(new, *s1, n1 + 1);
	ft_strlcat(new, s2, n1 + n2 + 1);
	ft_strdel(s1);
	return (new);
}
