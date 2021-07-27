#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_total;
	size_t	len_s1;
	size_t	len_s2;
	char	*new;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	len_total = len_s1 + len_s2;
	new = (char *)malloc(sizeof(char) * (len_total + 1));
	if (new)
	{
		ft_strlcpy(new, s1, len_s1 + 1);
		ft_strlcat(new, s2, len_total + 1);
	}
	return (new);
}
